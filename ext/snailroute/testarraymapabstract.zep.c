
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
#include "kernel/fcall.h"
#include "kernel/variables.h"


ZEPHIR_INIT_CLASS(SnailRoute_TestArrayMapAbstract) {

	ZEPHIR_REGISTER_CLASS(SnailRoute, TestArrayMapAbstract, snailroute, testarraymapabstract, snailroute_testarraymapabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(SnailRoute_TestArrayMapAbstract, process) {

}

PHP_METHOD(SnailRoute_TestArrayMapAbstract, run) {

	zval *_0 = NULL;
	zval *data = NULL, *users = NULL, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(users);
	zephir_create_array(users, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("name"), SL("Jock"), 1);
	add_assoc_long_ex(_0, SS("age"), 15);
	zephir_array_fast_append(users, _0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("name"), SL("Tom"), 1);
	add_assoc_long_ex(_0, SS("age"), 18);
	zephir_array_fast_append(users, _0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "process", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&data, "array_map", NULL, 7, _0, users);
	zephir_check_call_status();
	zephir_var_dump(&data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

