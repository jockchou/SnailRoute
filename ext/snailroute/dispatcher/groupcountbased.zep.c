
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SnailRoute_Dispatcher_GroupCountBased) {

	ZEPHIR_REGISTER_CLASS_EX(SnailRoute\\Dispatcher, GroupCountBased, snailroute, dispatcher_groupcountbased, snailroute_dispatcher_regexbasedabstract_ce, snailroute_dispatcher_groupcountbased_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(SnailRoute_Dispatcher_GroupCountBased, __construct) {

	zval *data_param = NULL, *_0, *_1;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_array_fetch_long(&_0, data, 0, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 9 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("staticRouteMap"), _0 TSRMLS_CC);
	zephir_array_fetch_long(&_1, data, 1, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 10 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("variableRouteData"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailRoute_Dispatcher_GroupCountBased, dispatchVariableRoute) {

	HashTable *_1, *_7$$3;
	HashPosition _0, _6$$3;
	int i;
	zval *uri = NULL;
	zval *routeData_param = NULL, *uri_param = NULL, *varName = NULL, *data = NULL, *matches = NULL, *handler = NULL, *varNames = NULL, *vars = NULL, *matchedRoute = NULL, **_2, *_11, *_3$$3 = NULL, *_4$$3, *_5$$3, **_8$$3, *_10$$3 = NULL, *_9$$5;
	zval *routeData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routeData_param, &uri_param);

	zephir_get_arrval(routeData, routeData_param);
	zephir_get_strval(uri, uri_param);


	ZEPHIR_INIT_VAR(vars);
	array_init(vars);
	i = 0;
	zephir_is_iterable(routeData, &_1, &_0, 0, 0, "snailroute/Dispatcher/GroupCountBased.zep", 34);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(data, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_array_fetch_string(&_4$$3, data, SL("regex"), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 19 TSRMLS_CC);
		zephir_preg_match(_3$$3, _4$$3, uri, matches, 0, 0 , 0  TSRMLS_CC);
		if (!zephir_is_true(_3$$3)) {
			continue;
		}
		zephir_array_fetch_string(&_5$$3, data, SL("routeMap"), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 23 TSRMLS_CC);
		zephir_array_fetch_long(&matchedRoute, _5$$3, zephir_fast_count_int(matches TSRMLS_CC), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 23 TSRMLS_CC);
		zephir_array_fetch_long(&handler, matchedRoute, 0, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 24 TSRMLS_CC);
		zephir_array_fetch_long(&varNames, matchedRoute, 1, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 25 TSRMLS_CC);
		zephir_is_iterable(varNames, &_7$$3, &_6$$3, 0, 0, "snailroute/Dispatcher/GroupCountBased.zep", 31);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$3, (void**) &_8$$3, &_6$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$3, &_6$$3)
		) {
			ZEPHIR_GET_HVALUE(varName, _8$$3);
			i = (i + 1);
			zephir_array_fetch_long(&_9$$5, matches, i, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/GroupCountBased.zep", 29 TSRMLS_CC);
			zephir_array_update_zval(&vars, varName, &_9$$5, PH_COPY | PH_SEPARATE);
		}
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10$$3);
		ZVAL_LONG(_10$$3, 1);
		zephir_array_fast_append(return_value, _10$$3);
		zephir_array_fast_append(return_value, handler);
		zephir_array_fast_append(return_value, vars);
		RETURN_MM();
	}
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	zephir_array_fast_append(return_value, _11);
	RETURN_MM();

}

