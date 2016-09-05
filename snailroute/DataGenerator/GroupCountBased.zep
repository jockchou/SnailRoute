namespace SnailRoute\DataGenerator;

class GroupCountBased extends RegexBasedAbstract
{
    public function getApproxChunkSize() -> int
    {
        return 10;
    }

    public function processChunk(var regexToRoutesMap) -> array
    {
        var routeMap = [], regexes = [], numGroups = 0, regex, route, numVariables, regexStr;
        
        for regex, route in regexToRoutesMap {
            let numVariables = count(route->variables);
            let numGroups = max(numGroups, numVariables);

            let regexes[] = regex . str_repeat("()", numGroups - numVariables);
            let routeMap[numGroups + 1] = [route->handler, route->variables];

            let numGroups = numGroups + 1;
        }
        
        let regexStr = "~^(?|" . implode("|", regexes) . ")$~";
       
        return ["regex": regexStr, "routeMap": routeMap];
    }
}
