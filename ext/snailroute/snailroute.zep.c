
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(SnailRoute_SnailRoute) {

	ZEPHIR_REGISTER_CLASS(SnailRoute, SnailRoute, snailroute, snailroute, snailroute_snailroute_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(SnailRoute_SnailRoute, simpleDispatcher) {

	zend_class_entry *_2, *_5, *_8, *_10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *callback, *options_param = NULL, *routeCollector = NULL, *defaultOpts = NULL, *routeCollectorClass = NULL, *routeParserClass = NULL, *dataGeneratorClass = NULL, *dispatcherClass = NULL, *_0, *_1 = NULL, *_3, *_4 = NULL, *_6, *_7 = NULL, *_9 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(defaultOpts);
	zephir_create_array(defaultOpts, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(defaultOpts, SS("routeParser"), SL("SnailRoute\\RouteParser\\StdRouteParser"), 1);
	add_assoc_stringl_ex(defaultOpts, SS("dataGenerator"), SL("SnailRoute\\DataGenerator\\GroupCountBased"), 1);
	add_assoc_stringl_ex(defaultOpts, SS("dispatcher"), SL("SnailRoute\\Dispatcher\\GroupCountBased"), 1);
	add_assoc_stringl_ex(defaultOpts, SS("routeCollector"), SL("SnailRoute\\RouteCollector"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(options), &(defaultOpts) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _0);
	ZEPHIR_OBS_VAR(routeCollectorClass);
	zephir_array_fetch_string(&routeCollectorClass, options, SL("routeCollector"), PH_NOISY, "snailroute/SnailRoute.zep", 20 TSRMLS_CC);
	ZEPHIR_OBS_VAR(routeParserClass);
	zephir_array_fetch_string(&routeParserClass, options, SL("routeParser"), PH_NOISY, "snailroute/SnailRoute.zep", 21 TSRMLS_CC);
	ZEPHIR_OBS_VAR(dataGeneratorClass);
	zephir_array_fetch_string(&dataGeneratorClass, options, SL("dataGenerator"), PH_NOISY, "snailroute/SnailRoute.zep", 22 TSRMLS_CC);
	ZEPHIR_OBS_VAR(dispatcherClass);
	zephir_array_fetch_string(&dispatcherClass, options, SL("dispatcher"), PH_NOISY, "snailroute/SnailRoute.zep", 23 TSRMLS_CC);
	ZEPHIR_INIT_VAR(routeCollector);
	zephir_fetch_safe_class(_1, routeCollectorClass);
		_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(routeCollector, _2);
	if (zephir_has_constructor(routeCollector TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3);
		zephir_fetch_safe_class(_4, routeParserClass);
			_5 = zend_fetch_class(Z_STRVAL_P(_4), Z_STRLEN_P(_4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_3, _5);
		if (zephir_has_constructor(_3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_6);
		zephir_fetch_safe_class(_7, dataGeneratorClass);
			_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_6, _8);
		if (zephir_has_constructor(_6 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, routeCollector, "__construct", NULL, 0, _3, _6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, callback, NULL, 0, routeCollector);
	zephir_check_call_status();
	zephir_fetch_safe_class(_9, dispatcherClass);
		_10 = zend_fetch_class(Z_STRVAL_P(_9), Z_STRLEN_P(_9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _10);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_11, routeCollector, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _11);
		zephir_check_call_status();
	}
	RETURN_MM();

}

