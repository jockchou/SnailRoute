namespace SnailRoute\RouteParser;

use SnailRoute\RouteParserInterface;

/**
 * Parses route strings of the following form:
 *
 * "/user/{name}[/{id:[0-9]+}]"
 */
class Std implements RouteParserInterface
{

    const VARIABLE_REGEX = "
\{
    \s* ([a-zA-Z_][a-zA-Z0-9_-]*) \s*
    (?:
        : \s* ([^{}]*(?:\{(?-1)\}[^{}]*)*)
    )?
\}";
 
    const DEFAULT_DISPATCH_REGEX = "[^/]+";
    
    public function parse(string route)
    {
        var withoutClosingOpt, numOptionals, segments, n, segment, currentRoute = "", routeDatas = [];
        
        let withoutClosingOpt = rtrim(route, "]");
        let numOptionals = strlen(route) - strlen(withoutClosingOpt);
        let segments = preg_split("~" . self::VARIABLE_REGEX . "(*SKIP)(*F) | \[~x", withoutClosingOpt);
        
        
        if numOptionals !== count(segments) - 1 {
            // If there are any ] in the middle of the route, throw a more specific error message
            if (preg_match("~" . self::VARIABLE_REGEX . "(*SKIP)(*F) | \]~x", withoutClosingOpt)) {
                throw new \Exception("Optional segments can only occur at the end of a route");
            }
            throw new \Exception("Number of opening '[' and closing ']' does not match");
        }
        
        for n, segment in segments {
            if segment === "" && n !== 0 {
                throw new \Exception("Empty optional part");
            }
            let currentRoute = currentRoute . segment;
            let routeDatas[] = this->parsePlaceholders(currentRoute);
        }
        
        return routeDatas;
    }
    
    private function parsePlaceholders(string route) {
        var set, matches = [], offset = 0, routeData = [];
        
        if (!preg_match_all("~" . self::VARIABLE_REGEX . "~x", route, matches, PREG_OFFSET_CAPTURE | PREG_SET_ORDER)) {
            return [route];
        }
        
        for set in matches {
 
            if set[0][1] > offset {
                let routeData[] = substr(route, offset, set[0][1] - offset);
            }
            
            let routeData[] = [
                set[1][0],
                isset set[2] ? trim(set[2][0]) : self::DEFAULT_DISPATCH_REGEX
            ];
            
            let offset = set[0][1] + strlen(set[0][0]);
        }
        
        if offset != strlen(route) {
            let routeData[] = substr(route, offset);
        }
        
        return routeData;
    }
}