
extern zend_class_entry *snailroute_routeparserinterface_ce;

ZEPHIR_INIT_CLASS(SnailRoute_RouteParserInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routeparserinterface_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_routeparserinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailRoute_RouteParserInterface, parse, arginfo_snailroute_routeparserinterface_parse)
	PHP_FE_END
};
