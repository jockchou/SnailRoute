namespace SnailRoute\Dispatcher;

use SnailRoute\DispatcherInterface;

abstract class RegexBasedAbstract implements DispatcherInterface {
    
    protected staticRouteMap;
    protected variableRouteData;

    protected abstract function dispatchVariableRoute(array routeData, string uri);

    public function dispatch(string httpMethod, string uri) -> array
    {
        var handler, varRouteData, result;
        
        if isset this->staticRouteMap[httpMethod][uri] {
            let handler = this->staticRouteMap[httpMethod][uri];
            return [self::FOUND, handler, []];
        }
        
        let varRouteData = this->variableRouteData;
        
        if isset varRouteData[httpMethod] {
            let result = this->dispatchVariableRoute(varRouteData[httpMethod], uri);
            if (result[0] === self::FOUND) {
                return result;
            }
        }
        die();
        // For HEAD requests, attempt fallback to GET
        if httpMethod === "HEAD" {
            if isset this->staticRouteMap["GET"][uri] {
                let handler = this->staticRouteMap["GET"][uri];
                return [self::FOUND, handler, []];
            }
            
            if isset varRouteData["GET"] {
                let result = this->dispatchVariableRoute(varRouteData["GET"], uri);
                if result[0] === self::FOUND {
                    return result;
                }
            }
        }

        // If nothing else matches, try fallback routes
        if isset this->staticRouteMap["*"][uri] {
            let handler = this->staticRouteMap["*"][uri];
            return [self::FOUND, handler, []];
        }
        if isset varRouteData["*"] {
            let result = this->dispatchVariableRoute(varRouteData["*"], uri);
            if result[0] === self::FOUND {
                return result;
            }
        }
       
        // Find allowed methods for this URI by matching against all other HTTP methods as well
        var routeData, method, uriMap, allowedMethods = [];
        
        for method, uriMap in this->staticRouteMap {
            if (method !== httpMethod && isset uriMap[uri]) {
                let allowedMethods[] = method;
            }
        }
        
        for method, routeData in varRouteData {
            if method === httpMethod {
                continue;
            }

            let result = this->dispatchVariableRoute(routeData, uri);
            if result[0] === self::FOUND {
                let allowedMethods[] = method;
            }
        }
   
        // If there are no allowed methods the route simply does not exist
        if !empty allowedMethods {
            return [self::METHOD_NOT_ALLOWED, allowedMethods];
        } else {
            return [self::NOT_FOUND];
        }
        
    }
}