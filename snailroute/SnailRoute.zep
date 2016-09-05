namespace SnailRoute;

class SnailRoute
{

    public static function simpleDispatcher(callable callback, array options = [])
    {
    
        var routeCollector, defaultOpts, routeCollectorClass, routeParserClass, dataGeneratorClass, dispatcherClass;
        
        let defaultOpts = [
            "routeParser" : "SnailRoute\\RouteParser\\StdRouteParser",
            "dataGenerator" : "SnailRoute\\DataGenerator\\GroupCountBased",
            "dispatcher" : "SnailRoute\\Dispatcher\\GroupCountBased",
            "routeCollector" : "SnailRoute\\RouteCollector"
        ];
        
        let options = array_merge(options, defaultOpts);
        
        let routeCollectorClass = options["routeCollector"];
        let routeParserClass = options["routeParser"];
        let dataGeneratorClass = options["dataGenerator"];
        let dispatcherClass = options["dispatcher"];
        
        let routeCollector = new {routeCollectorClass}(new {routeParserClass}(), new {dataGeneratorClass}());
        
        {callback}(routeCollector);
        
        return new {dispatcherClass}(routeCollector->getData());
    }
}