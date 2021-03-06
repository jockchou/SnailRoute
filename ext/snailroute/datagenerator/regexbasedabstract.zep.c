
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/math.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SnailRoute_DataGenerator_RegexBasedAbstract) {

	ZEPHIR_REGISTER_CLASS(SnailRoute\\DataGenerator, RegexBasedAbstract, snailroute, datagenerator_regexbasedabstract, snailroute_datagenerator_regexbasedabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(snailroute_datagenerator_regexbasedabstract_ce, SL("staticRoutes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailroute_datagenerator_regexbasedabstract_ce, SL("methodToRegexToRoutesMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	snailroute_datagenerator_regexbasedabstract_ce->create_object = zephir_init_properties_SnailRoute_DataGenerator_RegexBasedAbstract;

	zend_class_implements(snailroute_datagenerator_regexbasedabstract_ce TSRMLS_CC, 1, snailroute_datageneratorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, getApproxChunkSize) {

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, processChunk) {

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, addRoute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routeData = NULL;
	zval *httpMethod_param = NULL, *routeData_param = NULL, *handler, *_0 = NULL;
	zval *httpMethod = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod_param, &routeData_param, &handler);

	zephir_get_strval(httpMethod, httpMethod_param);
	zephir_get_arrval(routeData, routeData_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstaticroute", NULL, 1, routeData);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addstaticroute", NULL, 2, httpMethod, routeData, handler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addvariableroute", NULL, 3, httpMethod, routeData, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, getData) {

	zval *_0, *_3, *_4 = NULL, *_1$$3, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property_this(&_1$$3, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, _1$$3);
		ZEPHIR_INIT_VAR(_2$$3);
		array_init(_2$$3);
		zephir_array_fast_append(return_value, _2$$3);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	zephir_array_fast_append(return_value, _3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "generatevariableroutedata", NULL, 4);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _4);
	RETURN_MM();

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, generateVariableRouteData) {

	zval *_7$$3 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *method = NULL, *chunkSize = NULL, *chunks = NULL, *regexToRoutesMap = NULL, *data = NULL, *_0, **_3, *_4$$3 = NULL, *_8$$3 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(data);
	array_init(data);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "snailroute/DataGenerator/RegexBasedAbstract.zep", 43);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(method, _2, _1);
		ZEPHIR_GET_HVALUE(regexToRoutesMap, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, zephir_fast_count_int(regexToRoutesMap TSRMLS_CC));
		ZEPHIR_CALL_METHOD(&chunkSize, this_ptr, "computechunksize", &_5, 5, _4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&chunks, "array_chunk", &_6, 6, regexToRoutesMap, chunkSize, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7$$3);
		zephir_create_array(_7$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_7$$3, this_ptr);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "processChunk", 1);
		zephir_array_fast_append(_7$$3, _4$$3);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "array_map", &_9, 7, _7$$3, chunks);
		zephir_check_call_status();
		zephir_array_update_zval(&data, method, &_8$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, computeChunkSize) {

	zval *count_param = NULL, *numParts = NULL, *_0, *_1 = NULL, _2, *_3, _4;
	int count, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getapproxchunksize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_DOUBLE(&_2, zephir_safe_div_long_zval(count, _1 TSRMLS_CC));
	zephir_round(_0, &_2, NULL, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 1);
	ZEPHIR_CALL_FUNCTION(&numParts, "max", NULL, 8, _3, _0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, zephir_safe_div_long_zval(count, numParts TSRMLS_CC));
	RETURN_MM_DOUBLE(zephir_ceil(&_4 TSRMLS_CC));

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, isStaticRoute) {

	zend_bool _0;
	zval *routeData_param = NULL, *_1;
	zval *routeData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routeData_param);

	zephir_get_arrval(routeData, routeData_param);


	_0 = zephir_fast_count_int(routeData TSRMLS_CC) == 1;
	if (_0) {
		zephir_array_fetch_long(&_1, routeData, 0, PH_NOISY | PH_READONLY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 54 TSRMLS_CC);
		_0 = Z_TYPE_P(_1) == IS_STRING;
	}
	RETURN_MM_BOOL(_0);

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, addStaticRoute) {

	HashTable *_10$$4;
	HashPosition _9$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *routeData = NULL;
	zval *httpMethod_param = NULL, *routeData_param = NULL, *handler, *route = NULL, *routeStr = NULL, *_0, *_1, *_6, *_2$$3, _3$$3, *_4$$3 = NULL, *_7$$4, *_8$$4, **_11$$4, *_12$$5 = NULL, *_13$$6 = NULL, *_14$$6 = NULL, _15$$6 = zval_used_for_init, *_16$$6 = NULL;
	zval *httpMethod = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod_param, &routeData_param, &handler);

	zephir_get_strval(httpMethod, httpMethod_param);
	zephir_get_arrval(routeData, routeData_param);


	ZEPHIR_OBS_VAR(routeStr);
	zephir_array_fetch_long(&routeStr, routeData, 0, PH_NOISY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 59 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, httpMethod, PH_READONLY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 61 TSRMLS_CC);
	if (zephir_array_isset(_1, routeStr)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "Cannot register two routes matching \"%s\" for method \"%s\"", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", &_5, 9, &_3$$3, routeStr, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 10, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "snailroute/DataGenerator/RegexBasedAbstract.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	if (zephir_array_isset(_6, httpMethod)) {
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
		zephir_array_fetch(&_8$$4, _7$$4, httpMethod, PH_NOISY | PH_READONLY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 69 TSRMLS_CC);
		zephir_is_iterable(_8$$4, &_10$$4, &_9$$4, 0, 0, "snailroute/DataGenerator/RegexBasedAbstract.zep", 77);
		for (
		  ; zephir_hash_get_current_data_ex(_10$$4, (void**) &_11$$4, &_9$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10$$4, &_9$$4)
		) {
			ZEPHIR_GET_HVALUE(route, _11$$4);
			ZEPHIR_CALL_METHOD(&_12$$5, route, "matches", NULL, 0, routeStr);
			zephir_check_call_status();
			if (zephir_is_true(_12$$5)) {
				ZEPHIR_INIT_NVAR(_13$$6);
				object_init_ex(_13$$6, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_OBS_NVAR(_14$$6);
				zephir_read_property(&_14$$6, route, SL("regex"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_15$$6);
				ZVAL_STRING(&_15$$6, "Static route \"%s\" is shadowed by previously defined variable route \"%s\" for method \"%s\"", 0);
				ZEPHIR_CALL_FUNCTION(&_16$$6, "sprintf", &_5, 9, &_15$$6, routeStr, _14$$6, httpMethod);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _13$$6, "__construct", NULL, 10, _16$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_13$$6, "snailroute/DataGenerator/RegexBasedAbstract.zep", 74 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_update_property_array_multi(this_ptr, SL("staticRoutes"), &handler TSRMLS_CC, SL("zz"), 2, httpMethod, routeStr);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, addVariableRoute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routeData = NULL;
	zval *httpMethod_param = NULL, *routeData_param = NULL, *handler, *tmpData = NULL, *regex = NULL, *variables = NULL, *_0, *_1, *_5, *_2$$3, _3$$3, *_4$$3 = NULL;
	zval *httpMethod = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod_param, &routeData_param, &handler);

	zephir_get_strval(httpMethod, httpMethod_param);
	zephir_get_arrval(routeData, routeData_param);


	ZEPHIR_CALL_METHOD(&tmpData, this_ptr, "buildregexforroute", NULL, 11, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(regex);
	zephir_array_fetch_long(&regex, tmpData, 0, PH_NOISY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 87 TSRMLS_CC);
	ZEPHIR_OBS_VAR(variables);
	zephir_array_fetch_long(&variables, tmpData, 1, PH_NOISY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 88 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, httpMethod, PH_READONLY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 90 TSRMLS_CC);
	if (zephir_array_isset(_1, regex)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "Cannot register two routes matching \"%s\" for method \"%s\"", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 9, &_3$$3, regex, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 10, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "snailroute/DataGenerator/RegexBasedAbstract.zep", 94 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, snailroute_route_ce);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 12, httpMethod, handler, regex, variables);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("methodToRegexToRoutesMap"), &_5 TSRMLS_CC, SL("zz"), 2, httpMethod, regex);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, buildRegexForRoute) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL;
	zval *routeData_param = NULL, *varName = NULL, *regexPart = NULL, *part = NULL, *regex = NULL, *variables = NULL, **_2, _3$$4 = zval_used_for_init, *_4$$4 = NULL, *_6$$4 = NULL, *_7$$5 = NULL, _8$$5 = zval_used_for_init, *_9$$5 = NULL, *_12$$3 = NULL, *_17$$3 = NULL, *_14$$6 = NULL, _15$$6 = zval_used_for_init, *_16$$6 = NULL;
	zval *routeData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routeData_param);

	zephir_get_arrval(routeData, routeData_param);


	ZEPHIR_INIT_VAR(regex);
	ZVAL_STRING(regex, "", 1);
	ZEPHIR_INIT_VAR(variables);
	array_init(variables);
	zephir_is_iterable(routeData, &_1, &_0, 0, 0, "snailroute/DataGenerator/RegexBasedAbstract.zep", 131);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(part, _2);
		if (Z_TYPE_P(part) == IS_STRING) {
			ZEPHIR_SINIT_NVAR(_3$$4);
			ZVAL_STRING(&_3$$4, "~", 0);
			ZEPHIR_CALL_FUNCTION(&_4$$4, "preg_quote", &_5, 13, part, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_6$$4);
			ZEPHIR_CONCAT_VV(_6$$4, regex, _4$$4);
			ZEPHIR_CPY_WRT(regex, _6$$4);
			continue;
		}
		ZEPHIR_OBS_NVAR(varName);
		zephir_array_fetch_long(&varName, part, 0, PH_NOISY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 111 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(regexPart);
		zephir_array_fetch_long(&regexPart, part, 1, PH_NOISY, "snailroute/DataGenerator/RegexBasedAbstract.zep", 112 TSRMLS_CC);
		if (zephir_array_isset(variables, varName)) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_SINIT_NVAR(_8$$5);
			ZVAL_STRING(&_8$$5, "Cannot use the same placeholder \"%s\" twice", 0);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", &_10, 9, &_8$$5, varName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_11, 10, _9$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "snailroute/DataGenerator/RegexBasedAbstract.zep", 117 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "regexhascapturinggroups", &_13, 14, regexPart);
		zephir_check_call_status();
		if (zephir_is_true(_12$$3)) {
			ZEPHIR_INIT_NVAR(_14$$6);
			object_init_ex(_14$$6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_SINIT_NVAR(_15$$6);
			ZVAL_STRING(&_15$$6, "Regex \"%s\" for parameter \"%s\" contains a capturing group", 0);
			ZEPHIR_CALL_FUNCTION(&_16$$6, "sprintf", &_10, 9, &_15$$6, regexPart, varName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _14$$6, "__construct", &_11, 10, _16$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_14$$6, "snailroute/DataGenerator/RegexBasedAbstract.zep", 124 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&variables, varName, &varName, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_17$$3);
		ZEPHIR_CONCAT_VSVS(_17$$3, regex, "(", regexPart, ")");
		ZEPHIR_CPY_WRT(regex, _17$$3);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, regex);
	zephir_array_fast_append(return_value, variables);
	RETURN_MM();

}

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, regexHasCapturingGroups) {

	zval *regex_param = NULL, _0, *_1, *_2, _3;
	zval *regex = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regex_param);

	zephir_get_strval(regex, regex_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "(", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, regex, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "~\n                (?:\n                    \\(\\?\\(\n                  | \\[ [^\\]\\\\]* (?: \\\\ . [^\\]\\\\]* )* \\]\n                  | \\\\ .\n                ) (*SKIP)(*FAIL) |\n                \\(\n                (?!\n                    \\? (?! <(?![!=]) | P< | \\' )\n                  | \\*\n                )\n            ~x", 0);
	zephir_preg_match(return_value, &_3, regex, _2, 0, 0 , 0  TSRMLS_CC);
	RETURN_MM();

}

zend_object_value zephir_init_properties_SnailRoute_DataGenerator_RegexBasedAbstract(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("methodToRegexToRoutesMap"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("staticRoutes"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

