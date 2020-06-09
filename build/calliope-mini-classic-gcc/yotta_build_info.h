#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 17 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 42 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 33 // UTC second 0-61
#define YOTTA_BUILD_UUID 25b05d48-fd58-42cd-82f0-7fd548e5bc2a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'aea7e8b4fc6bbdb8d920f67fac91ea07ad3548df' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'aea7e8b' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
