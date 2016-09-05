
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


ZEPHIR_INIT_CLASS(SnailRoute_TestArrayMap) {

	ZEPHIR_REGISTER_CLASS_EX(SnailRoute, TestArrayMap, snailroute, testarraymap, snailroute_testarraymapabstract_ce, snailroute_testarraymap_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(SnailRoute_TestArrayMap, process) {

	zval *user, *regex = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user);



	ZEPHIR_INIT_VAR(regex);
	ZVAL_STRING(regex, "~^(?|/user/(\d+)|/user/(\d+)/([^/]+))$~", 1);
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("regex"), &regex, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("user"), &user, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

