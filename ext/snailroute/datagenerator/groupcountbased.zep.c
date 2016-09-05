
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SnailRoute_DataGenerator_GroupCountBased) {

	ZEPHIR_REGISTER_CLASS_EX(SnailRoute\\DataGenerator, GroupCountBased, snailroute, datagenerator_groupcountbased, snailroute_datagenerator_regexbasedabstract_ce, snailroute_datagenerator_groupcountbased_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(SnailRoute_DataGenerator_GroupCountBased, getApproxChunkSize) {

	

	RETURN_LONG(10);

}

PHP_METHOD(SnailRoute_DataGenerator_GroupCountBased, processChunk) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS, _12$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zval *regexToRoutesMap_param = NULL, *routeMap = NULL, *regexes = NULL, *numGroups = NULL, *regex = NULL, *route = NULL, *numVariables = NULL, *regexStr = NULL, **_2, *_13, *_3$$3 = NULL, *_4$$3 = NULL, _6$$3 = zval_used_for_init, _7$$3 = zval_used_for_init, *_9$$3 = NULL, *_11$$3 = NULL;
	zval *regexToRoutesMap = NULL, *_10$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regexToRoutesMap_param);

	zephir_get_arrval(regexToRoutesMap, regexToRoutesMap_param);


	ZEPHIR_INIT_VAR(routeMap);
	array_init(routeMap);
	ZEPHIR_INIT_VAR(regexes);
	array_init(regexes);
	ZEPHIR_INIT_VAR(numGroups);
	ZVAL_LONG(numGroups, 0);
	zephir_is_iterable(regexToRoutesMap, &_1, &_0, 0, 0, "snailroute/DataGenerator/GroupCountBased.zep", 24);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(regex, _1, _0);
		ZEPHIR_GET_HVALUE(route, _2);
		ZEPHIR_OBS_NVAR(_3$$3);
		zephir_read_property(&_3$$3, route, SL("variables"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(numVariables);
		ZVAL_LONG(numVariables, zephir_fast_count_int(_3$$3 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_4$$3, "max", &_5, 8, numGroups, numVariables);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(numGroups, _4$$3);
		ZEPHIR_SINIT_NVAR(_6$$3);
		zephir_sub_function(&_6$$3, numGroups, numVariables);
		ZEPHIR_SINIT_NVAR(_7$$3);
		ZVAL_STRING(&_7$$3, "()", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "str_repeat", &_8, 15, &_7$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_VV(_9$$3, regex, _4$$3);
		zephir_array_append(&regexes, _9$$3, PH_SEPARATE, "snailroute/DataGenerator/GroupCountBased.zep", 18);
		ZEPHIR_INIT_NVAR(_10$$3);
		zephir_create_array(_10$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_11$$3);
		zephir_read_property(&_11$$3, route, SL("handler"), PH_NOISY_CC);
		zephir_array_fast_append(_10$$3, _11$$3);
		ZEPHIR_OBS_NVAR(_11$$3);
		zephir_read_property(&_11$$3, route, SL("variables"), PH_NOISY_CC);
		zephir_array_fast_append(_10$$3, _11$$3);
		zephir_array_update_long(&routeMap, (zephir_get_numberval(numGroups) + 1), &_10$$3, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		_12$$3 = (zephir_get_numberval(numGroups) + 1);
		ZEPHIR_INIT_NVAR(numGroups);
		ZVAL_LONG(numGroups, _12$$3);
	}
	ZEPHIR_INIT_VAR(_13);
	zephir_fast_join_str(_13, SL("|"), regexes TSRMLS_CC);
	ZEPHIR_INIT_VAR(regexStr);
	ZEPHIR_CONCAT_SVS(regexStr, "~^(?|", _13, ")$~");
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("regex"), &regexStr, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("routeMap"), &routeMap, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

