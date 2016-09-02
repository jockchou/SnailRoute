namespace SnailRoute\Dispatcher;

use SnailRoute\DispatcherInterface;

class GroupCountBased extends RegexBasedAbstract
{
    public function __construct(array data) {
    
        let this->staticRouteMap = data[0];
        let this->variableRouteData = data[1];
    } 
    
    protected function dispatchVariableRoute(array routeData, string uri) {
        
        var varName, data, matches, handler, varNames, vars= [], i = 0, matchedRoute;
        
        for data in routeData {
        
            if (!preg_match(data["regex"], uri, matches)) {
                continue;
            }
            
            let matchedRoute = data["routeMap"][count(matches)];
            let handler = matchedRoute[0];
            let varNames = matchedRoute[1];
            
            for varName in varNames {
                let i = i + 1;
                let vars[varName] = matches[i];
            }
            return [DispatcherInterface::FOUND, handler, vars];
        }

        return [DispatcherInterface::NOT_FOUND];
    }
}