
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(SnailRoute_RouteCollector) {

	ZEPHIR_REGISTER_CLASS(SnailRoute, RouteCollector, snailroute, routecollector, snailroute_routecollector_method_entry, 0);

	zend_declare_property_null(snailroute_routecollector_ce, SL("routeParser"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailroute_routecollector_ce, SL("dataGenerator"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructs a route collector.
 *
 * @param <RouteParserInterface>   routeParser
 * @param <DataGeneratorInterface> dataGenerator
 */
PHP_METHOD(SnailRoute_RouteCollector, __construct) {

	zval *routeParser, *dataGenerator;

	zephir_fetch_params(0, 2, 0, &routeParser, &dataGenerator);



	zephir_update_property_this(this_ptr, SL("routeParser"), routeParser TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("dataGenerator"), dataGenerator TSRMLS_CC);

}

/**
 * Adds a route to the collection.
 *
 * The syntax used in the $route string depends on the used route parser.
 *
 * @param string|array httpMethod
 * @param string route
 * @param callable handler
 */
PHP_METHOD(SnailRoute_RouteCollector, addRoute) {

	HashTable *_3, *_6$$3;
	HashPosition _2, _5$$3;
	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route = NULL;
	zval *httpMethod, *route_param = NULL, *handler, *routeDatas = NULL, *routeData = NULL, *method = NULL, *_0, **_4, **_7$$3, *_8$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &route_param, &handler);

	zephir_get_strval(route, route_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("routeParser"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&routeDatas, _0, "parse", NULL, 0, route);
	zephir_check_call_status();
	zephir_get_arrval(_1, httpMethod);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "snailroute/RouteCollector.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(method, _4);
		zephir_is_iterable(routeDatas, &_6$$3, &_5$$3, 0, 0, "snailroute/RouteCollector.zep", 38);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HVALUE(routeData, _7$$3);
			_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dataGenerator"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _8$$4, "addroute", NULL, 0, method, routeData, handler);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the collected route data, as provided by the data generator.
 *
 * @return array
 */
PHP_METHOD(SnailRoute_RouteCollector, getData) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataGenerator"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

