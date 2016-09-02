namespace SnailRoute;

class Route
{
    public httpMethod;
    public regex;
    public variables;
    public handler;
    
    /**
     * Constructs a route (value object).
     *
     * @param string httpMethod
     * @param callable  handler
     * @param string regex
     * @param array  variables
     */
    public function __construct(string httpMethod, callable handler, string regex, array variables)
    {
        let this->httpMethod = httpMethod;
        let this->handler = handler;
        let this->regex = regex;
        let this->variables = variables;
    }
    
    /**
     * Tests whether this route matches the given string.
     *
     * @param string str
     *
     * @return bool
     */
    public function matches(string str) -> boolean
    {
        string regex;
        let regex = "~^" . this->regex . "$~";
        return (bool) preg_match(regex, str);
    }
}