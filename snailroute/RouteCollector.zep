namespace SnailRoute;

class RouteCollector
{
    private routeParser;
    private dataGenerator;
    
    /**
     * Constructs a route collector.
     *
     * @param <RouteParserInterface>   routeParser
     * @param <DataGeneratorInterface> dataGenerator
     */
    public function __construct(<RouteParserInterface> routeParser, <DataGeneratorInterface> dataGenerator) {
        let this->routeParser = routeParser;
        let this->dataGenerator = dataGenerator;
    }
    
    /**
     * Adds a route to the collection.
     *
     * The syntax used in the route string depends on the used route parser.
     *
     * @param string|array httpMethod
     * @param string route
     * @param callable handler
     */
    public function addRoute(var httpMethod, string route, callable handler)
    {
        var routeDatas, routeData, method, httpMethods = null;
        
        let routeDatas = this->routeParser->parse(route);
        
        if typeof httpMethod == "string" {
            let httpMethods = [httpMethod];
        } elseif typeof httpMethod == "array" {
            let httpMethods = httpMethod;
        } else {
            throw new \Exception("Invalid parameter type in httpMethod.");
        }
        
        for method in httpMethods {
            for routeData in routeDatas {
                this->dataGenerator->addRoute(method, routeData, handler);
            }
        }
    }
    
    /**
     * Returns the collected route data, as provided by the data generator.
     *
     * @return array
     */
    public function getData() -> array
    {
        return this->dataGenerator->getData();
    }
}