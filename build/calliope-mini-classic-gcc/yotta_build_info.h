#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 7 // UTC month 1-12
#define YOTTA_BUILD_DAY 28 // UTC day 1-31
#define YOTTA_BUILD_HOUR 7 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 44 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 19 // UTC second 0-61
#define YOTTA_BUILD_UUID f33bffd9-e28b-47a3-bc21-61532be3d153 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'8fb56700690452b858f88363be9f57a4543352ed' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'8fb5670' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
