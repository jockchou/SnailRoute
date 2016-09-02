
extern zend_class_entry *snailroute_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(SnailRoute_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_dispatcherinterface_dispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailRoute_DispatcherInterface, dispatch, arginfo_snailroute_dispatcherinterface_dispatch)
	PHP_FE_END
};
