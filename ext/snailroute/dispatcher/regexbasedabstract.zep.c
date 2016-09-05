
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exit.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(SnailRoute_Dispatcher_RegexBasedAbstract) {

	ZEPHIR_REGISTER_CLASS(SnailRoute\\Dispatcher, RegexBasedAbstract, snailroute, dispatcher_regexbasedabstract, snailroute_dispatcher_regexbasedabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(snailroute_dispatcher_regexbasedabstract_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailroute_dispatcher_regexbasedabstract_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(snailroute_dispatcher_regexbasedabstract_ce TSRMLS_CC, 1, snailroute_dispatcherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailRoute_Dispatcher_RegexBasedAbstract, dispatchVariableRoute) {

}

PHP_METHOD(SnailRoute_Dispatcher_RegexBasedAbstract, dispatch) {

	zend_bool _26$$13;
	HashTable *_24, *_28;
	HashPosition _23, _27;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod_param = NULL, *uri_param = NULL, *handler = NULL, *varRouteData = NULL, *result = NULL, *_0, *_1, *_15, *_16, *routeData = NULL, *method = NULL, *uriMap = NULL, *allowedMethods = NULL, *_22, **_25, **_29, *_2$$3, *_3$$3, *_4$$3 = NULL, *_5$$4, *_7$$4, *_8$$6, *_9$$6, *_10$$7, *_11$$7, *_12$$7 = NULL, *_13$$8, *_14$$8, *_17$$10, *_18$$10, *_19$$10 = NULL, *_20$$11, *_21$$11, *_30$$15, *_31$$18, *_32$$19;
	zval *httpMethod = NULL, *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod_param, &uri_param);

	zephir_get_strval(httpMethod, httpMethod_param);
	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, httpMethod, PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 16 TSRMLS_CC);
	if (zephir_array_isset(_1, uri)) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch(&_3$$3, _2$$3, httpMethod, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 17 TSRMLS_CC);
		ZEPHIR_OBS_VAR(handler);
		zephir_array_fetch(&handler, _3$$3, uri, PH_NOISY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 17 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, 1);
		zephir_array_fast_append(return_value, _4$$3);
		zephir_array_fast_append(return_value, handler);
		ZEPHIR_INIT_NVAR(_4$$3);
		array_init(_4$$3);
		zephir_array_fast_append(return_value, _4$$3);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(varRouteData);
	zephir_read_property_this(&varRouteData, this_ptr, SL("variableRouteData"), PH_NOISY_CC);
	if (zephir_array_isset(varRouteData, httpMethod)) {
		zephir_array_fetch(&_5$$4, varRouteData, httpMethod, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 24 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_6, 0, _5$$4, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_7$$4, result, 0, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 25 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_7$$4, 1)) {
			RETURN_CCTOR(result);
		}
	}
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	if (ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD")) {
		_8$$6 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch_string(&_9$$6, _8$$6, SL("GET"), PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 32 TSRMLS_CC);
		if (zephir_array_isset(_9$$6, uri)) {
			_10$$7 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
			zephir_array_fetch_string(&_11$$7, _10$$7, SL("GET"), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 33 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(handler);
			zephir_array_fetch(&handler, _11$$7, uri, PH_NOISY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 33 TSRMLS_CC);
			zephir_create_array(return_value, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12$$7);
			ZVAL_LONG(_12$$7, 1);
			zephir_array_fast_append(return_value, _12$$7);
			zephir_array_fast_append(return_value, handler);
			ZEPHIR_INIT_NVAR(_12$$7);
			array_init(_12$$7);
			zephir_array_fast_append(return_value, _12$$7);
			RETURN_MM();
		}
		if (zephir_array_isset_string(varRouteData, SS("GET"))) {
			zephir_array_fetch_string(&_13$$8, varRouteData, SL("GET"), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 38 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_6, 0, _13$$8, uri);
			zephir_check_call_status();
			zephir_array_fetch_long(&_14$$8, result, 0, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 39 TSRMLS_CC);
			if (ZEPHIR_IS_LONG_IDENTICAL(_14$$8, 1)) {
				RETURN_CCTOR(result);
			}
		}
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
	zephir_array_fetch_string(&_16, _15, SL("*"), PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 46 TSRMLS_CC);
	if (zephir_array_isset(_16, uri)) {
		_17$$10 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch_string(&_18$$10, _17$$10, SL("*"), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 47 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(handler);
		zephir_array_fetch(&handler, _18$$10, uri, PH_NOISY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 47 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_19$$10);
		ZVAL_LONG(_19$$10, 1);
		zephir_array_fast_append(return_value, _19$$10);
		zephir_array_fast_append(return_value, handler);
		ZEPHIR_INIT_NVAR(_19$$10);
		array_init(_19$$10);
		zephir_array_fast_append(return_value, _19$$10);
		RETURN_MM();
	}
	if (zephir_array_isset_string(varRouteData, SS("*"))) {
		zephir_array_fetch_string(&_20$$11, varRouteData, SL("*"), PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 51 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_6, 0, _20$$11, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_21$$11, result, 0, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 52 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_21$$11, 1)) {
			RETURN_CCTOR(result);
		}
	}
	ZEPHIR_INIT_VAR(allowedMethods);
	array_init(allowedMethods);
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
	zephir_is_iterable(_22, &_24, &_23, 0, 0, "snailroute/Dispatcher/RegexBasedAbstract.zep", 66);
	for (
	  ; zephir_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
	  ; zephir_hash_move_forward_ex(_24, &_23)
	) {
		ZEPHIR_GET_HMKEY(method, _24, _23);
		ZEPHIR_GET_HVALUE(uriMap, _25);
		_26$$13 = !ZEPHIR_IS_IDENTICAL(method, httpMethod);
		if (_26$$13) {
			_26$$13 = zephir_array_isset(uriMap, uri);
		}
		if (_26$$13) {
			zephir_array_append(&allowedMethods, method, PH_SEPARATE, "snailroute/Dispatcher/RegexBasedAbstract.zep", 62);
		}
	}
	zephir_is_iterable(varRouteData, &_28, &_27, 0, 0, "snailroute/Dispatcher/RegexBasedAbstract.zep", 78);
	for (
	  ; zephir_hash_get_current_data_ex(_28, (void**) &_29, &_27) == SUCCESS
	  ; zephir_hash_move_forward_ex(_28, &_27)
	) {
		ZEPHIR_GET_HMKEY(method, _28, _27);
		ZEPHIR_GET_HVALUE(routeData, _29);
		if (ZEPHIR_IS_IDENTICAL(method, httpMethod)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_6, 0, routeData, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_30$$15, result, 0, PH_NOISY | PH_READONLY, "snailroute/Dispatcher/RegexBasedAbstract.zep", 72 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_30$$15, 1)) {
			zephir_array_append(&allowedMethods, method, PH_SEPARATE, "snailroute/Dispatcher/RegexBasedAbstract.zep", 73);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(allowedMethods))) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_31$$18);
		ZVAL_LONG(_31$$18, 2);
		zephir_array_fast_append(return_value, _31$$18);
		zephir_array_fast_append(return_value, allowedMethods);
		RETURN_MM();
	} else {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_32$$19);
		ZVAL_LONG(_32$$19, 0);
		zephir_array_fast_append(return_value, _32$$19);
		RETURN_MM();
	}

}

