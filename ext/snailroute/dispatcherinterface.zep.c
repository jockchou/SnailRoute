
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(SnailRoute_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailRoute, DispatcherInterface, snailroute, dispatcherinterface, snailroute_dispatcherinterface_method_entry);

	zend_declare_class_constant_long(snailroute_dispatcherinterface_ce, SL("NOT_FOUND"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(snailroute_dispatcherinterface_ce, SL("FOUND"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(snailroute_dispatcherinterface_ce, SL("METHOD_NOT_ALLOWED"), 2 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Dispatches against the provided HTTP method verb and URI.
 *
 * Returns array with one of the following formats:
 *
 *     [self::NOT_FOUND]
 *     [self::METHOD_NOT_ALLOWED, ['GET', 'OTHER_ALLOWED_METHODS']]
 *     [self::FOUND, $handler, ['varName' => 'value', ...]]
 *
 * @param string httpMethod
 * @param string uri
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(SnailRoute_DispatcherInterface, dispatch);

