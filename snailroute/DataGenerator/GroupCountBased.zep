namespace SnailRoute\DataGenerator;

class GroupCountBased extends RegexBasedAbstract
{
    protected function getApproxChunkSize()
    {
        return 10;
    }

    protected function processChunk(var regexToRoutesMap)
    {
        var routeMap = [], regexes = [], numGroups = 0, regex, route, numVariables;
        
        for regex, route in regexToRoutesMap {
            let numVariables = count(route->variables);
            let numGroups = max(numGroups, numVariables);

            let regexes[] = regex . str_repeat("()", numGroups - numVariables);
            let routeMap[numGroups + 1] = [route->handler, route->variables];

            let numGroups = numGroups + 1;
        }

        let regex = "~^(?|" . implode("|", regexes) . ")$~";
        return ["regex" : regex, "routeMap" : routeMap];
    }
}
