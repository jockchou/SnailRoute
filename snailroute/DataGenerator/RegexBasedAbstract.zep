namespace SnailRoute\DataGenerator;

use SnailRoute\DataGeneratorInterface;
use SnailRoute\Route;

abstract class RegexBasedAbstract implements DataGeneratorInterface
{

    protected staticRoutes = [];
    protected methodToRegexToRoutesMap = [];

    public abstract function getApproxChunkSize() -> int;
    public abstract function processChunk(array regexToRoutesMap) -> array;
    
    public function addRoute(string httpMethod, array routeData, callable handler) {
        if this->isStaticRoute(routeData) {
            this->addStaticRoute(httpMethod, routeData, handler);
        } else {
            this->addVariableRoute(httpMethod, routeData, handler);
        }
    }

    public function getData() -> array {
        if empty this->methodToRegexToRoutesMap {
            return [this->staticRoutes, []];
        }

        return [this->staticRoutes, this->generateVariableRouteData()];
    }

    
    private function generateVariableRouteData() -> array
    {
        var method, chunkSize, chunks, regexToRoutesMap, data = [];
        
        for method, regexToRoutesMap in this->methodToRegexToRoutesMap {
            let chunkSize = this->computeChunkSize(count(regexToRoutesMap));
            let chunks = array_chunk(regexToRoutesMap, chunkSize, true);
           
            let data[method] = array_map([this, "processChunk"], chunks);
        }
        
        return data;
    }

    private function computeChunkSize(int count)
    {
        var numParts = max(1, round(count / this->getApproxChunkSize()));
        return ceil(count / numParts);
    }

    private function isStaticRoute(array routeData) -> boolean
    {
        return count(routeData) === 1 && is_string(routeData[0]);
    }

    private function addStaticRoute(string httpMethod, array routeData, callable handler)
    {
        var route, routeStr = routeData[0];

        if isset this->staticRoutes[httpMethod][routeStr] {
            throw new \Exception(sprintf(
                "Cannot register two routes matching \"%s\" for method \"%s\"",
                routeStr, httpMethod
            ));
        }

        if isset this->methodToRegexToRoutesMap[httpMethod] {
            for route in this->methodToRegexToRoutesMap[httpMethod] {
                if route->matches(routeStr) {
                    throw new \Exception(sprintf(
                        "Static route \"%s\" is shadowed by previously defined variable route \"%s\" for method \"%s\"",
                        routeStr, route->regex, httpMethod
                    ));
                }
            }
        }

        let this->staticRoutes[httpMethod][routeStr] = handler;
    }

    private function addVariableRoute(string httpMethod, array routeData, callable handler)
    {
        var tmpData, regex, variables;
        
        let tmpData = this->buildRegexForRoute(routeData);
        let regex = tmpData[0];
        let variables = tmpData[1];
        
        if isset this->methodToRegexToRoutesMap[httpMethod][regex] {
            throw new \Exception(sprintf(
                "Cannot register two routes matching \"%s\" for method \"%s\"",
                regex, httpMethod
            ));
        }

        let this->methodToRegexToRoutesMap[httpMethod][regex] = new Route(
            httpMethod, handler, regex, variables
        );
    }

    private function buildRegexForRoute(array routeData) -> array
    {
        var varName, regexPart, part, regex = "", variables = [];
        for part in routeData {
            if is_string(part) {
                let regex = regex . preg_quote(part, "~");
                continue;
            }
            
            let varName = part[0];
            let regexPart = part[1];
            
            if isset variables[varName] {
                throw new \Exception(sprintf(
                    "Cannot use the same placeholder \"%s\" twice", varName
                ));
            }

            if this->regexHasCapturingGroups(regexPart) {
                throw new \Exception(sprintf(
                    "Regex \"%s\" for parameter \"%s\" contains a capturing group",
                    regexPart, varName
                ));
            }

            let variables[varName] = varName;
            let regex =  regex . "(" . regexPart . ")";
        }

        return [regex, variables];
    }

    private function regexHasCapturingGroups(string regex) -> boolean
    {
    
        if false === strpos(regex, "(") {
            // Needs to have at least a ( to contain a capturing group
            return false;
        }

        // Semi-accurate detection for capturing groups
        return preg_match(
            "~
                (?:
                    \(\?\(
                  | \[ [^\]\\\\]* (?: \\\\ . [^\]\\\\]* )* \]
                  | \\\\ .
                ) (*SKIP)(*FAIL) |
                \(
                (?!
                    \? (?! <(?![!=]) | P< | \' )
                  | \*
                )
            ~x",
            regex
        );
    }
}