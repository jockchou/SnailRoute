<?php

use SnailRoute\SnailRoute;
use SnailRoute\DispatcherInterface;


// Fetch method and URI from somewhere
$httpMethod = $_SERVER['REQUEST_METHOD'];
$uri = $_SERVER['REQUEST_URI'];

// Strip query string (?foo=bar) and decode URI
if (false !== $pos = strpos($uri, '?')) {
    $uri = substr($uri, 0, $pos);
}
$uri = rawurldecode($uri);


$dispatcher = SnailRoute::simpleDispatcher(function($r) {
    $r->addRoute('GET', '/user/{id:\d+}[/{name}]', function($vars) {
       var_dump($vars);
       echo "111" ;
    });
});

$routeInfo = $dispatcher->dispatch($httpMethod, $uri);

switch ($routeInfo[0]) {
    case DispatcherInterface::NOT_FOUND:
        // ... 404 Not Found
        break;
    case DispatcherInterface::METHOD_NOT_ALLOWED:
        $allowedMethods = $routeInfo[1];
        // ... 405 Method Not Allowed
        break;
    case DispatcherInterface::FOUND:
        $handler = $routeInfo[1];
        $vars = $routeInfo[2];
        // ... call $handler with $vars
        
        //var_dump($handler);
        $handler($vars);
        
        break;
}