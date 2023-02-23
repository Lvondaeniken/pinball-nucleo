/**
 *
 */

namespace Pinball
{
    namespace Events
    {
        const char slingshotLeft[] = "sl\n";
        const char slingshotRight[] = "sr\n";
        const char flipRight[] = "fr\n";
        const char flipLeft[] = "fl\n";
        const char bmp1[] = "b1\n";
        const char bmp2[] = "b2\n";
        const char bmp3[] = "b3\n";
        const char ballshooter[] = "bs\n";
        const char target1[] = "t1\n";
        const char target2[] = "t2\n";
        const char target3[] = "t3\n";
        const char lightbar1[] = "lb1";
        const char lightbar2[] = "lb2";
        const char lightbar3[] = "lb3";
        const char lightbar4[] = "lb4";
        const char lightbar5[] = "lb5";
        const char lightbar6[] = "lb6";
        const char lightbar7[] = "lb7";

        enum class ESource
        {
            eSlingshotLeft = 0,
            eSlingshotRight,
            eKickerLeft,
            eKickerRight,
            eBumper1,
            eBumper2,
            eBumper3,
            eBallshooter,
            eTarget1,
            eTarget2,
            eTarget3,
            eLightbar1,
            eLightbar2,
            eLightbar3,
            eLightbar4,
            eLightbar5,
            eLightbar6,
            eLightbar7,

        };

        enum class ECoil
        {
            eSlingshotLeft = 0,
            eSlingshotRight,
            eKickerLeft,
            eKickerRight,
            eBumper1,
            eBumper2,
            eBumper3,
            eBallshooter,
            eMagazine,
        };
    }
}
