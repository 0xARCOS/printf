#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h"

// Colores para output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

int test_count = 0;
int passed = 0;
int failed = 0;

void print_test_header(const char *category)
{
    printf("\n" BLUE "========================================\n");
    printf("  %s\n", category);
    printf("========================================\n" RESET);
}

void compare_results(const char *test_name, int ft_ret, int printf_ret)
{
    test_count++;
    if (ft_ret == printf_ret)
    {
        printf(GREEN "✓ PASS" RESET " | %s | ft: %d, printf: %d\n", 
               test_name, ft_ret, printf_ret);
        passed++;
    }
    else
    {
        printf(RED "✗ FAIL" RESET " | %s | ft: %d, printf: %d\n", 
               test_name, ft_ret, printf_ret);
        failed++;
    }
}

void test_char(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: %c (CHARACTER)");
    
    printf("Expected: ");
    printf_ret = printf("%c", 'a');
    printf("\nGot:      ");
    ft_ret = ft_printf("%c", 'a');
    printf("\n");
    compare_results("Simple char 'a'", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%c%c%c", 'A', 'B', 'C');
    printf("\nGot:      ");
    ft_ret = ft_printf("%c%c%c", 'A', 'B', 'C');
    printf("\n");
    compare_results("Multiple chars", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%c", '\0');
    printf("\nGot:      ");
    ft_ret = ft_printf("%c", '\0');
    printf("\n");
    compare_results("Null character", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%c", 127);
    printf("\nGot:      ");
    ft_ret = ft_printf("%c", 127);
    printf("\n");
    compare_results("DEL character (127)", ft_ret, printf_ret);
}

void test_string(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: %s (STRING)");
    
    printf("Expected: ");
    printf_ret = printf("%s", "Hello World");
    printf("\nGot:      ");
    ft_ret = ft_printf("%s", "Hello World");
    printf("\n");
    compare_results("Simple string", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%s", "");
    printf("\nGot:      ");
    ft_ret = ft_printf("%s", "");
    printf("\n");
    compare_results("Empty string", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%s", "(null)");
    printf("\nGot:      ");
    ft_ret = ft_printf("%s", (char *)NULL);
    printf("\n");
    compare_results("NULL string", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%s%s%s", "one", "two", "three");
    printf("\nGot:      ");
    ft_ret = ft_printf("%s%s%s", "one", "two", "three");
    printf("\n");
    compare_results("Multiple strings", ft_ret, printf_ret);
}

void test_pointer(void)
{
    int ft_ret, printf_ret;
    int a = 42;
    void *ptr = &a;
    
    print_test_header("TEST: %p (POINTER)");
    
    printf("Expected: ");
    printf_ret = printf("%p", ptr);
    printf("\nGot:      ");
    ft_ret = ft_printf("%p", ptr);
    printf("\n");
    compare_results("Normal pointer", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%p", (void *)NULL);
    printf("\nGot:      ");
    ft_ret = ft_printf("%p", (void *)NULL);
    printf("\n");
    compare_results("NULL pointer", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%p", (void *)0);
    printf("\nGot:      ");
    ft_ret = ft_printf("%p", (void *)0);
    printf("\n");
    compare_results("Zero pointer", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%p%p", ptr, (void *)NULL);
    printf("\nGot:      ");
    ft_ret = ft_printf("%p%p", ptr, (void *)NULL);
    printf("\n");
    compare_results("Multiple pointers", ft_ret, printf_ret);
}

void test_decimal(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: %d and %i (DECIMAL)");
    
    printf("Expected: ");
    printf_ret = printf("%d", 42);
    printf("\nGot:      ");
    ft_ret = ft_printf("%d", 42);
    printf("\n");
    compare_results("Positive number", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%d", -42);
    printf("\nGot:      ");
    ft_ret = ft_printf("%d", -42);
    printf("\n");
    compare_results("Negative number", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%d", 0);
    printf("\nGot:      ");
    ft_ret = ft_printf("%d", 0);
    printf("\n");
    compare_results("Zero", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%d", INT_MAX);
    printf("\nGot:      ");
    ft_ret = ft_printf("%d", INT_MAX);
    printf("\n");
    compare_results("INT_MAX", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%d", INT_MIN);
    printf("\nGot:      ");
    ft_ret = ft_printf("%d", INT_MIN);
    printf("\n");
    compare_results("INT_MIN", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%i", (int)-2147483648);
    printf("\nGot:      ");
    ft_ret = ft_printf("%i", (int)-2147483648);
    printf("\n");
    compare_results("INT_MIN with %%i", ft_ret, printf_ret);
}

void test_unsigned(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: %u (UNSIGNED)");
    
    printf("Expected: ");
    printf_ret = printf("%u", 42);
    printf("\nGot:      ");
    ft_ret = ft_printf("%u", 42);
    printf("\n");
    compare_results("Positive unsigned", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%u", 0);
    printf("\nGot:      ");
    ft_ret = ft_printf("%u", 0);
    printf("\n");
    compare_results("Zero unsigned", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%u", UINT_MAX);
    printf("\nGot:      ");
    ft_ret = ft_printf("%u", UINT_MAX);
    printf("\n");
    compare_results("UINT_MAX", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%u", -1);
    printf("\nGot:      ");
    ft_ret = ft_printf("%u", -1);
    printf("\n");
    compare_results("Negative as unsigned", ft_ret, printf_ret);
}

void test_hex(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: %x and %X (HEXADECIMAL)");
    
    printf("Expected: ");
    printf_ret = printf("%x", 42);
    printf("\nGot:      ");
    ft_ret = ft_printf("%x", 42);
    printf("\n");
    compare_results("Lowercase hex (42)", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%X", 42);
    printf("\nGot:      ");
    ft_ret = ft_printf("%X", 42);
    printf("\n");
    compare_results("Uppercase hex (42)", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%x", 0);
    printf("\nGot:      ");
    ft_ret = ft_printf("%x", 0);
    printf("\n");
    compare_results("Zero in hex", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%x", 255);
    printf("\nGot:      ");
    ft_ret = ft_printf("%x", 255);
    printf("\n");
    compare_results("255 in hex (ff)", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%X", 255);
    printf("\nGot:      ");
    ft_ret = ft_printf("%X", 255);
    printf("\n");
    compare_results("255 in HEX (FF)", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%x", -1);
    printf("\nGot:      ");
    ft_ret = ft_printf("%x", -1);
    printf("\n");
    compare_results("-1 in hex (ffffffff)", ft_ret, printf_ret);
}

void test_percent(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: %% (PERCENT)");
    
    printf("Expected: ");
    printf_ret = printf("%%");
    printf("\nGot:      ");
    ft_ret = ft_printf("%%");
    printf("\n");
    compare_results("Single percent", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%%%%");
    printf("\nGot:      ");
    ft_ret = ft_printf("%%%%");
    printf("\n");
    compare_results("Double percent", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("100%%");
    printf("\nGot:      ");
    ft_ret = ft_printf("100%%");
    printf("\n");
    compare_results("Percent with text", ft_ret, printf_ret);
}

void test_mixed(void)
{
    int ft_ret, printf_ret;
    
    print_test_header("TEST: MIXED CONVERSIONS");
    
    printf("Expected: ");
    printf_ret = printf("Hello %s, you have %d messages (%x)", "Alice", 5, 255);
    printf("\nGot:      ");
    ft_ret = ft_printf("Hello %s, you have %d messages (%x)", "Alice", 5, 255);
    printf("\n");
    compare_results("String, decimal, hex", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("%c%s%p%d%i%u%x%X%%", 'A', "test", (void *)42, -42, 42, 42, 42, 42);
    printf("\nGot:      ");
    ft_ret = ft_printf("%c%s%p%d%i%u%x%X%%", 'A', "test", (void *)42, -42, 42, 42, 42, 42);
    printf("\n");
    compare_results("All conversions", ft_ret, printf_ret);
    
    printf("Expected: ");
    printf_ret = printf("   ");
    printf("\nGot:      ");
    ft_ret = ft_printf("   ");
    printf("\n");
    compare_results("Only spaces", ft_ret, printf_ret);
    
    // Test empty string - just compare return values
    printf("Expected: (empty)");
    printf_ret = 0; // Empty string returns 0
    printf("\nGot:      ");
    ft_ret = ft_printf("");
    printf("\n");
    compare_results("Empty string", ft_ret, printf_ret);
}

void print_summary(void)
{
    printf("\n" YELLOW "========================================\n");
    printf("           TEST SUMMARY\n");
    printf("========================================\n" RESET);
    printf("Total tests: %d\n", test_count);
    printf(GREEN "Passed: %d\n" RESET, passed);
    printf(RED "Failed: %d\n" RESET, failed);
    
    if (failed == 0)
        printf(GREEN "\n🎉 ALL TESTS PASSED! 🎉\n" RESET);
    else
        printf(RED "\n⚠️  SOME TESTS FAILED ⚠️\n" RESET);
    
    printf(YELLOW "========================================\n" RESET);
}

int main(void)
{
    printf(BLUE "\n");
    printf("╔═══════════════════════════════════════╗\n");
    printf("║     FT_PRINTF COMPREHENSIVE TESTER   ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    printf(RESET);
    
    test_char();
    test_string();
    test_pointer();
    test_decimal();
    test_unsigned();
    test_hex();
    test_percent();
    test_mixed();
    
    print_summary();
    
    return (0);
}