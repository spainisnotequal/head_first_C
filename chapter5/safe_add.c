/*
 * Program to see how useful unions and enums are
 */

#include <stdio.h>
#include <limits.h>


enum type_of_value {
        VALUE, ERROR
};

struct safe_short {
        union { // anonymous union, added in the C11 standard
                short value;
                short error;
        };
        enum type_of_value type;
};

struct safe_short safe_add(short a, short b)
{
        struct safe_short safe_result;
        
        if (((b > 0) && (a > SHRT_MAX - b)) ||    // overflow
            ((b < 0) && (a < SHRT_MIN - b)))      // underflow
        {
                safe_result.type = ERROR;
                safe_result.error = -1;
        }
        else
        {
                safe_result.type = VALUE;
                safe_result.value = a + b;
        }
        return safe_result;        
}

int main(){

        short a = 2;
        short b = -5;

        const struct safe_short sum1 = safe_add(a, b);
        if (sum1.type == ERROR)
                printf("Addition failed (line %d, file '%s')\n",
                       __LINE__, __FILE__);
        else
                printf("%hi + %hi = %hi\n", a, b, sum1.value);

        const struct safe_short sum2 = safe_add(SHRT_MAX, a);
        if (sum2.type == ERROR)
                printf("Addition failed (line %d, file '%s')\n",
                       __LINE__, __FILE__);
        else
                printf("%hi + %hi = %hi\n", SHRT_MAX, a, sum2.value);

        const struct safe_short sum3 = safe_add(SHRT_MIN, b);
        if (sum3.type == ERROR)
                printf("Addition failed (line %d, file '%s')\n",
                       __LINE__, __FILE__);
        else
                printf("%hi + %hi = %hi\n", SHRT_MIN, b, sum3.value);
        
	return 0;
}
