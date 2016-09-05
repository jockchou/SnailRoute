
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(SnailRoute_RouteParserInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailRoute, RouteParserInterface, snailroute, routeparserinterface, snailroute_routeparserinterface_method_entry);

	return SUCCESS;

}

/**
 * Parses a route string into multiple route data arrays.
 *
 * The expected output is defined using an example:
 *
 * For the route string "/fixedRoutePart/{varName}[/moreFixed/{varName2:\d+}]", if {varName} is interpreted as
 * a placeholder and [...] is interpreted as an optional route part, the expected result is:
 *
 * [
 *     // first route: without optional part
 *     [
 *         "/fixedRoutePart/",
 *         ["varName", "[^/]+"],
 *     ],
 *     // second route: with optional part
 *     [
 *         "/fixedRoutePart/",
 *         ["varName", "[^/]+"],
 *         "/moreFixed/",
 *         ["varName2", "[0-9]+"],
 *     ],
 * ]
 *
 * Here one route string was converted into two route data arrays.
 *
 * @param string route Route string to parse
 * 
 * @return mixed[][] Array of route data arrays
 */
ZEPHIR_DOC_METHOD(SnailRoute_RouteParserInterface, parse);

