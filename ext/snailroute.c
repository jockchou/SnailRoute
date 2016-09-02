
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "snailroute.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *snailroute_datageneratorinterface_ce;
zend_class_entry *snailroute_dispatcherinterface_ce;
zend_class_entry *snailroute_routeparserinterface_ce;
zend_class_entry *snailroute_datagenerator_regexbasedabstract_ce;
zend_class_entry *snailroute_dispatcher_regexbasedabstract_ce;
zend_class_entry *snailroute_datagenerator_groupcountbased_ce;
zend_class_entry *snailroute_dispatcher_groupcountbased_ce;
zend_class_entry *snailroute_route_ce;
zend_class_entry *snailroute_routecollector_ce;
zend_class_entry *snailroute_routeparser_std_ce;
zend_class_entry *snailroute_snailroute_ce;

ZEND_DECLARE_MODULE_GLOBALS(snailroute)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(snailroute)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(SnailRoute_DataGeneratorInterface);
	ZEPHIR_INIT(SnailRoute_DispatcherInterface);
	ZEPHIR_INIT(SnailRoute_RouteParserInterface);
	ZEPHIR_INIT(SnailRoute_DataGenerator_RegexBasedAbstract);
	ZEPHIR_INIT(SnailRoute_Dispatcher_RegexBasedAbstract);
	ZEPHIR_INIT(SnailRoute_DataGenerator_GroupCountBased);
	ZEPHIR_INIT(SnailRoute_Dispatcher_GroupCountBased);
	ZEPHIR_INIT(SnailRoute_Route);
	ZEPHIR_INIT(SnailRoute_RouteCollector);
	ZEPHIR_INIT(SnailRoute_RouteParser_Std);
	ZEPHIR_INIT(SnailRoute_SnailRoute);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(snailroute)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_snailroute_globals *snailroute_globals TSRMLS_DC)
{
	snailroute_globals->initialized = 0;

	/* Memory options */
	snailroute_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	snailroute_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	snailroute_globals->cache_enabled = 1;

	/* Recursive Lock */
	snailroute_globals->recursive_lock = 0;

	/* Static cache */
	memset(snailroute_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_snailroute_globals *snailroute_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(snailroute)
{

	zend_snailroute_globals *snailroute_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(snailroute_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(snailroute_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(snailroute)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(snailroute)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SNAILROUTE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SNAILROUTE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SNAILROUTE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SNAILROUTE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SNAILROUTE_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(snailroute)
{
	php_zephir_init_globals(snailroute_globals TSRMLS_CC);
	php_zephir_init_module_globals(snailroute_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(snailroute)
{

}


zend_function_entry php_snailroute_functions[] = {
ZEND_FE_END

};

zend_module_entry snailroute_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SNAILROUTE_EXTNAME,
	php_snailroute_functions,
	PHP_MINIT(snailroute),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(snailroute),
#else
	NULL,
#endif
	PHP_RINIT(snailroute),
	PHP_RSHUTDOWN(snailroute),
	PHP_MINFO(snailroute),
	PHP_SNAILROUTE_VERSION,
	ZEND_MODULE_GLOBALS(snailroute),
	PHP_GINIT(snailroute),
	PHP_GSHUTDOWN(snailroute),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SNAILROUTE
ZEND_GET_MODULE(snailroute)
#endif
