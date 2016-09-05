
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"


/**
 * Parses route strings of the following form:
 *
 * "/user/{name}[/{id:[0-9]+}]"
 */
ZEPHIR_INIT_CLASS(SnailRoute_RouteParser_Std) {

	ZEPHIR_REGISTER_CLASS(SnailRoute\\RouteParser, Std, snailroute, routeparser_std, snailroute_routeparser_std_method_entry, 0);

	zend_declare_class_constant_string(snailroute_routeparser_std_ce, SL("VARIABLE_REGEX"), "\n\\{\n    \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s*\n    (?:\n        : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*)\n    )?\n\\}" TSRMLS_CC);

	zend_declare_class_constant_string(snailroute_routeparser_std_ce, SL("DEFAULT_DISPATCH_REGEX"), "[^/]+" TSRMLS_CC);

	zend_class_implements(snailroute_routeparser_std_ce TSRMLS_CC, 1, snailroute_routeparserinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailRoute_RouteParser_Std, parse) {

	zend_bool _8$$5;
	HashTable *_6;
	HashPosition _5;
	zephir_fcall_cache_entry *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route_param = NULL, *withoutClosingOpt = NULL, *numOptionals = NULL, *segments = NULL, *n = NULL, *segment = NULL, *currentRoute = NULL, *routeDatas = NULL, _0, **_7, *_2$$3, *_3$$3, *_9$$5 = NULL, *_10$$5 = NULL;
	zval *route = NULL, *_1, *_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route_param);

	zephir_get_strval(route, route_param);


	ZEPHIR_INIT_VAR(currentRoute);
	ZVAL_STRING(currentRoute, "", 1);
	ZEPHIR_INIT_VAR(routeDatas);
	array_init(routeDatas);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "]", 0);
	ZEPHIR_INIT_VAR(withoutClosingOpt);
	zephir_fast_trim(withoutClosingOpt, route, &_0, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(numOptionals);
	ZVAL_LONG(numOptionals, (zephir_fast_strlen_ev(route) - zephir_fast_strlen_ev(withoutClosingOpt)));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SSS(_1, "~", "\n\\{\n    \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s*\n    (?:\n        : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*)\n    )?\n\\}", "(*SKIP)(*F) | \\[~x");
	ZEPHIR_CALL_FUNCTION(&segments, "preg_split", NULL, 16, _1, withoutClosingOpt);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(numOptionals, (zephir_fast_count_int(segments TSRMLS_CC) - 1))) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_SSS(_4$$3, "~", "\n\\{\n    \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s*\n    (?:\n        : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*)\n    )?\n\\}", "(*SKIP)(*F) | \\]~x");
		zephir_preg_match(_3$$3, _4$$3, withoutClosingOpt, _2$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Optional segments can only occur at the end of a route", "snailroute/RouteParser/Std.zep", 29);
			return;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Number of opening '[' and closing ']' does not match", "snailroute/RouteParser/Std.zep", 31);
		return;
	}
	zephir_is_iterable(segments, &_6, &_5, 0, 0, "snailroute/RouteParser/Std.zep", 42);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(n, _6, _5);
		ZEPHIR_GET_HVALUE(segment, _7);
		_8$$5 = ZEPHIR_IS_STRING_IDENTICAL(segment, "");
		if (_8$$5) {
			_8$$5 = !ZEPHIR_IS_LONG_IDENTICAL(n, 0);
		}
		if (_8$$5) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Empty optional part", "snailroute/RouteParser/Std.zep", 36);
			return;
		}
		ZEPHIR_INIT_LNVAR(_9$$5);
		ZEPHIR_CONCAT_VV(_9$$5, currentRoute, segment);
		ZEPHIR_CPY_WRT(currentRoute, _9$$5);
		ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "parseplaceholders", &_11, 17, currentRoute);
		zephir_check_call_status();
		zephir_array_append(&routeDatas, _10$$5, PH_SEPARATE, "snailroute/RouteParser/Std.zep", 39);
	}
	RETURN_CCTOR(routeDatas);

}

PHP_METHOD(SnailRoute_RouteParser_Std, parsePlaceholders) {

	zval *_12$$4 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route_param = NULL, *set = NULL, *matches = NULL, *offset = NULL, *routeData = NULL, *_1, *_2 = NULL, **_5, *_6$$4, *_7$$4, *_13$$4, *_14$$4 = NULL, *_15$$4 = NULL, *_16$$4, *_17$$4, *_18$$4, *_19$$4, *_20$$4, *_21$$4, *_8$$5, *_9$$5, _10$$5 = zval_used_for_init, *_11$$5 = NULL, *_22$$6;
	zval *route = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route_param);

	zephir_get_strval(route, route_param);


	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(offset);
	ZVAL_LONG(offset, 0);
	ZEPHIR_INIT_VAR(routeData);
	array_init(routeData);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SSS(_0, "~", "\n\\{\n    \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s*\n    (?:\n        : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*)\n    )?\n\\}", "~x");
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (256 | 2));
	ZEPHIR_MAKE_REF(matches);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match_all", NULL, 18, _0, route, matches, _1);
	ZEPHIR_UNREF(matches);
	zephir_check_call_status();
	if (!zephir_is_true(_2)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, route);
		RETURN_MM();
	}
	zephir_is_iterable(matches, &_4, &_3, 0, 0, "snailroute/RouteParser/Std.zep", 66);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(set, _5);
		zephir_array_fetch_long(&_6$$4, set, 0, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 54 TSRMLS_CC);
		zephir_array_fetch_long(&_7$$4, _6$$4, 1, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 54 TSRMLS_CC);
		if (ZEPHIR_GT(_7$$4, offset)) {
			zephir_array_fetch_long(&_8$$5, set, 0, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 55 TSRMLS_CC);
			zephir_array_fetch_long(&_9$$5, _8$$5, 1, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 55 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_10$$5);
			zephir_sub_function(&_10$$5, _9$$5, offset);
			ZEPHIR_INIT_NVAR(_11$$5);
			zephir_substr(_11$$5, route, zephir_get_intval(offset), zephir_get_intval(&_10$$5), 0);
			zephir_array_append(&routeData, _11$$5, PH_SEPARATE, "snailroute/RouteParser/Std.zep", 55);
		}
		ZEPHIR_INIT_NVAR(_12$$4);
		zephir_create_array(_12$$4, 2, 0 TSRMLS_CC);
		zephir_array_fetch_long(&_13$$4, set, 1, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 59 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_14$$4);
		zephir_array_fetch_long(&_14$$4, _13$$4, 0, PH_NOISY, "snailroute/RouteParser/Std.zep", 59 TSRMLS_CC);
		zephir_array_fast_append(_12$$4, _14$$4);
		ZEPHIR_INIT_LNVAR(_15$$4);
		if (zephir_array_isset_long(set, 2)) {
			zephir_array_fetch_long(&_16$$4, set, 2, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 60 TSRMLS_CC);
			zephir_array_fetch_long(&_17$$4, _16$$4, 0, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 60 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_15$$4);
			zephir_fast_trim(_15$$4, _17$$4, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_15$$4);
			ZVAL_STRING(_15$$4, "[^/]+", 1);
		}
		zephir_array_fast_append(_12$$4, _15$$4);
		zephir_array_append(&routeData, _12$$4, PH_SEPARATE, "snailroute/RouteParser/Std.zep", 61);
		zephir_array_fetch_long(&_18$$4, set, 0, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 63 TSRMLS_CC);
		zephir_array_fetch_long(&_19$$4, _18$$4, 1, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 63 TSRMLS_CC);
		zephir_array_fetch_long(&_20$$4, set, 0, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 63 TSRMLS_CC);
		zephir_array_fetch_long(&_21$$4, _20$$4, 0, PH_NOISY | PH_READONLY, "snailroute/RouteParser/Std.zep", 63 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(offset);
		ZVAL_LONG(offset, (zephir_get_numberval(_19$$4) + zephir_fast_strlen_ev(_21$$4)));
	}
	if (!ZEPHIR_IS_LONG(offset, zephir_fast_strlen_ev(route))) {
		ZEPHIR_INIT_VAR(_22$$6);
		zephir_substr(_22$$6, route, zephir_get_intval(offset), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&routeData, _22$$6, PH_SEPARATE, "snailroute/RouteParser/Std.zep", 67);
	}
	RETURN_CCTOR(routeData);

}

