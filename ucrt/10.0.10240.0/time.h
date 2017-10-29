//
// time.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// The C Standard Library <time.h> header.
//
#pragma once
#define _INC_TIME

#include <corecrt.h>
#include <corecrt_wtime.h>

_CRT_BEGIN_C_HEADER



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Types
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
typedef long clock_t;

struct _timespec32
{
    __time32_t tv_sec;
    long       tv_nsec;
};

struct _timespec64
{
    __time64_t tv_sec;
    long       tv_nsec;
};

#ifndef _CRT_NO_TIME_T
    struct timespec
    {
        time_t tv_sec;  // Seconds - >= 0
        long   tv_nsec; // Nanoseconds - [0, 999999999]
    };
#endif



// The number of clock ticks per second
#define CLOCKS_PER_SEC  ((clock_t)1000)

#define TIME_UTC 1



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Time Zone and Daylight Savings Time Data and Accessors
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Nonzero if Daylight Savings Time is used
_ACRTIMP int _daylight;

_Check_return_ _CRT_INSECURE_DEPRECATE_GLOBALS(_get_daylight)
__inline int* __cdecl __daylight(void)
{
	return &_daylight;
}

// Offset for Daylight Savings Time
_ACRTIMP long _dstbias;

_Check_return_ _CRT_INSECURE_DEPRECATE_GLOBALS(_get_dstbias)
__inline long* __cdecl __dstbias(void)
{
	return &_dstbias;
}

// Difference in seconds between GMT and local time
_ACRTIMP long _timezone;

_Check_return_ _CRT_INSECURE_DEPRECATE_GLOBALS(_get_timezone)
__inline long* __cdecl __timezone(void)
{
	return &_timezone;
}

// Standard and Daylight Savings Time time zone names
_ACRTIMP char** _tzname;

_Check_return_ _Deref_ret_z_ _CRT_INSECURE_DEPRECATE_GLOBALS(_get_tzname)
__inline char** __cdecl __tzname(void)
{
	return _tzname;
}

 _Success_(_Daylight != 0)
_ACRTIMP errno_t __cdecl _get_daylight(
    _Out_ int* _Daylight
    );

_Success_(_DaylightSavingsBias != 0)
_ACRTIMP errno_t __cdecl _get_dstbias(
    _Out_ long* _DaylightSavingsBias
    );

 _Success_(_TimeZone != 0)
_ACRTIMP errno_t __cdecl _get_timezone(
    _Out_ long* _TimeZone
    );

_Success_(return == 0)
_ACRTIMP errno_t __cdecl _get_tzname(
    _Out_                        size_t* _ReturnValue,
    _Out_writes_z_(_SizeInBytes) char*   _Buffer,
    _In_                         size_t  _SizeInBytes,
    _In_                         int     _Index
    );



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// AppCRT Time Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
_Success_(return != 0)
_Ret_writes_z_(26)
_Check_return_ _CRT_INSECURE_DEPRECATE(asctime_s)
_ACRTIMP char* __cdecl asctime(
    _In_ struct tm const* _Tm
    );

#if __STDC_WANT_SECURE_LIB__
    _Success_(return == 0)
    _Check_return_wat_
    _ACRTIMP errno_t __cdecl asctime_s(
        _Out_writes_(_SizeInBytes) _Post_readable_size_(26) char*            _Buffer,
        _In_range_(>=,26)                                   size_t           _SizeInBytes,
        _In_                                                struct tm const* _Tm
        );
#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(
    errno_t, asctime_s,
    _Post_readable_size_(26) char,             _Buffer,
    _In_                     struct tm const*, _Time
    )

_Check_return_
_ACRTIMP clock_t __cdecl clock(void);

_Ret_z_
_Success_(return != 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(_ctime32_s)
_ACRTIMP char* __cdecl _ctime32(
    _In_ __time32_t const* _Time
    );

_Check_return_wat_
_ACRTIMP errno_t __cdecl _ctime32_s(
    _Out_writes_(_SizeInBytes) _Post_readable_size_(26) char*             _Buffer,
    _In_range_(>=,26)                                   size_t            _SizeInBytes,
    _In_                                                __time32_t const* _Time
    );

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(
    errno_t, _ctime32_s,
    _Post_readable_size_(26) char,              _Buffer,
    _In_                     __time32_t const*, _Time
    )

_Ret_z_
_Success_(return != 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(_ctime64_s)
_ACRTIMP char* __cdecl _ctime64(
    _In_ __time64_t const* _Time
    );

_Check_return_wat_
_ACRTIMP errno_t __cdecl _ctime64_s(
    _Out_writes_z_(_SizeInBytes) _Post_readable_size_(26) char*             _Buffer,
    _In_range_(>=,26)                                     size_t            _SizeInBytes,
    _In_                                                  __time64_t const* _Time
    );

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(
    errno_t, _ctime64_s,
    _Post_readable_size_(26) char,              _Buffer,
    _In_                     __time64_t const*, _Time
    )

_Check_return_
_ACRTIMP double __cdecl _difftime32(
    _In_ __time32_t _Time1,
    _In_ __time32_t _Time2
    );

_Check_return_
_ACRTXPIMP double __cdecl _difftime64(
    _In_ __time64_t _Time1,
    _In_ __time64_t _Time2
    );

_Success_(return != 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(_gmtime32_s)
_ACRTIMP struct tm* __cdecl _gmtime32(
    _In_ __time32_t const* _Time
    );

_Check_return_wat_
_ACRTIMP errno_t __cdecl _gmtime32_s(
    _Out_ struct tm*        _Tm,
    _In_  __time32_t const* _Time
    );

_Success_(return != 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(_gmtime64_s)
_ACRTIMP struct tm* __cdecl _gmtime64(
    _In_ __time64_t const* _Time
    );

_Check_return_wat_
_ACRTIMP errno_t __cdecl _gmtime64_s(
    _Out_ struct tm*        _Tm,
    _In_  __time64_t const* _Time
    );

_Success_(return != 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(_localtime32_s)
_ACRTIMP struct tm* __cdecl _localtime32(
    _In_ __time32_t const* _Time
    );

_Check_return_wat_
_ACRTIMP errno_t __cdecl _localtime32_s(
    _Out_ struct tm*        _Tm,
    _In_  __time32_t const* _Time
    );

_Success_(return != 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(_localtime64_s)
_ACRTIMP struct tm* __cdecl _localtime64(
    _In_ __time64_t const* _Time
    );

_Check_return_wat_
_ACRTXPIMP errno_t __cdecl _localtime64_s(
    _Out_ struct tm*        _Tm,
    _In_  __time64_t const* _Time
    );

_Check_return_
_ACRTIMP __time32_t __cdecl _mkgmtime32(
    _Inout_ struct tm* _Tm
    );

_Check_return_
_ACRTIMP __time64_t __cdecl _mkgmtime64(
    _Inout_ struct tm* _Tm
    );

_Check_return_opt_
_ACRTIMP __time32_t __cdecl _mktime32(
    _Inout_ struct tm* _Tm
    );

_Check_return_opt_
_ACRTIMP __time64_t __cdecl _mktime64(
    _Inout_ struct tm* _Tm
    );

_Success_(return > 0)
_Check_return_wat_
_ACRTIMP size_t __cdecl strftime(
    _Out_writes_z_(_SizeInBytes)  char*            _Buffer,
    _In_                          size_t           _SizeInBytes,
    _In_z_ _Printf_format_string_ char const*      _Format,
    _In_                          struct tm const* _Tm
    );

_Success_(return > 0)
_Check_return_wat_
_ACRTIMP size_t __cdecl _strftime_l(
    _Out_writes_z_(_MaxSize)      char*            _Buffer,
    _In_                          size_t           _MaxSize,
    _In_z_ _Printf_format_string_ char const*      _Format,
    _In_                          struct tm const* _Tm,
    _In_opt_                      _locale_t        _Locale
    );

_Check_return_wat_
_ACRTIMP errno_t __cdecl _strdate_s(
    _Out_writes_(_SizeInBytes) _Post_readable_size_(9) char*  _Buffer,
    _In_  _In_range_(>=, 9)                            size_t _SizeInBytes
    );

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(
    errno_t, _strdate_s,
    _Post_readable_size_(9) char, _Buffer
    )

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(
    _Success_(return != 0) char*, __RETURN_POLICY_DST, _ACRTIMP, _strdate,
    _Out_writes_z_(9), char, _Buffer
    )

_Check_return_wat_
_ACRTIMP errno_t __cdecl _strtime_s(
    _Out_writes_(_SizeInBytes) _Post_readable_size_(9) char*  _Buffer,
    _In_  _In_range_(>=, 9)                            size_t _SizeInBytes
    );

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(
    errno_t, _strtime_s,
    _Post_readable_size_(9) char, _Buffer
    )

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(
    char*, __RETURN_POLICY_DST, _ACRTIMP, _strtime,
    _Out_writes_z_(9), char, _Buffer
    )

_ACRTIMP __time32_t __cdecl _time32(
    _Out_opt_ __time32_t* _Time
    );

_ACRTXPIMP __time64_t __cdecl _time64(
    _Out_opt_ __time64_t* _Time
    );

_Success_(return != 0)
_Check_return_
_ACRTIMP int __cdecl _timespec32_get(
    _Out_ struct _timespec32* _Ts,
    _In_  int                 _Base
    );

_Success_(return != 0)
_Check_return_
_ACRTIMP int __cdecl _timespec64_get(
    _Out_ struct _timespec64* _Ts,
    _In_  int                 _Base
    );



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// DesktopCRT Time Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

    _ACRTIMP void __cdecl _tzset(void);

    // The Win32 API GetLocalTime and SetLocalTime should be used instead.
    _CRT_OBSOLETE(GetLocalTime)
    _DCRTIMP unsigned __cdecl _getsystime(
        _Out_ struct tm* _Tm
        );

    _CRT_OBSOLETE(SetLocalTime)
    _DCRTIMP unsigned __cdecl _setsystime(
        _In_ struct tm* _Tm,
        _In_ unsigned   _Milliseconds
        );

#endif



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Inline Function Definitions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#if !defined RC_INVOKED && !defined __midl && !defined _INC_TIME_INL && !defined _CRT_NO_TIME_T

    #ifdef _USE_32BIT_TIME_T

        _Check_return_ _CRT_INSECURE_DEPRECATE(ctime_s)
        static __inline char* __CRTDECL ctime(
            _In_ time_t const* const _Time
            )
        {
            #pragma warning(push)
            #pragma warning(disable: 4996)
            return _ctime32(_Time);
            #pragma warning(pop)
        }

        _Check_return_
        static __inline double __CRTDECL difftime(
            _In_ time_t const _Time1,
            _In_ time_t const _Time2
            )
        {
            return _difftime32(_Time1, _Time2);
        }

        _Check_return_ _CRT_INSECURE_DEPRECATE(gmtime_s)
        static __inline struct tm* __CRTDECL gmtime(
            _In_ time_t const* const _Time
            )
        {
            #pragma warning(push)
            #pragma warning(disable: 4996)
            return _gmtime32(_Time);
            #pragma warning(pop)
        }

        _Check_return_ _CRT_INSECURE_DEPRECATE(localtime_s)
        static __inline struct tm* __CRTDECL localtime(
            _In_ time_t const* const _Time
            )
        {
            #pragma warning(push)
            #pragma warning(disable: 4996)
            return _localtime32(_Time);
            #pragma warning(pop)
        }

        _Check_return_
        static __inline time_t __CRTDECL _mkgmtime(
            _Inout_ struct tm* const _Tm
            )
        {
            return _mkgmtime32(_Tm);
        }

        _Check_return_opt_
        static __inline time_t __CRTDECL mktime(
            _Inout_ struct tm* const _Tm
            )
        {
            return _mktime32(_Tm);
        }

        static __inline time_t __CRTDECL time(
            _Out_opt_ time_t* const _Time
            )
        {
            return _time32(_Time);
        }

        _Check_return_
        static __inline int __CRTDECL timespec_get(
            _Out_ struct timespec* const _Ts,
            _In_  int              const _Base
            )
        {
            return _timespec32_get((struct _timespec32*)_Ts, _Base); 
        }

        #if __STDC_WANT_SECURE_LIB__
            _Check_return_wat_
            static __inline errno_t __CRTDECL ctime_s(
                _Out_writes_(_SizeInBytes) _Post_readable_size_(26) char*         const _Buffer,
                _In_range_(>=,26)                                   size_t        const _SizeInBytes,
                _In_                                                time_t const* const _Time
                )
            {
                return _ctime32_s(_Buffer, _SizeInBytes, _Time);
            }

            _Check_return_wat_
            static __inline errno_t __CRTDECL gmtime_s(
                _Out_ struct tm*    const _Tm,
                _In_  time_t const* const _Time
                )
            {
                return _gmtime32_s(_Tm, _Time);
            }

            _Check_return_wat_
            static __inline errno_t __CRTDECL localtime_s(
                _Out_ struct tm*    const _Tm, 
                _In_  time_t const* const _Time
                )
            {
                return _localtime32_s(_Tm, _Time);
            }
        #endif

    #else // ^^^ _USE_32BIT_TIME_T ^^^ // vvv !_USE_32BIT_TIME_T vvv

        _Check_return_ _CRT_INSECURE_DEPRECATE(ctime_s)
        static __inline char* __CRTDECL ctime(
            _In_ time_t const* const _Time
            )
        {
            #pragma warning(push)
            #pragma warning(disable: 4996)
            return _ctime64(_Time);
            #pragma warning(pop)
        }

        _Check_return_
        static __inline double __CRTDECL difftime(
            _In_ time_t const _Time1,
            _In_ time_t const _Time2
            )
        {
            return _difftime64(_Time1, _Time2);
        }

        _Check_return_ _CRT_INSECURE_DEPRECATE(gmtime_s)
        static __inline struct tm* __CRTDECL gmtime(
            _In_ time_t const* const _Time)
        {
            #pragma warning(push)
            #pragma warning(disable: 4996)
            return _gmtime64(_Time);
            #pragma warning(pop)
        }

        _CRT_INSECURE_DEPRECATE(localtime_s)
        static __inline struct tm* __CRTDECL localtime(
            _In_ time_t const* const _Time
            )
        {
            #pragma warning(push)
            #pragma warning(disable: 4996)
            return _localtime64(_Time);
            #pragma warning(pop)
        }

        _Check_return_
        static __inline time_t __CRTDECL _mkgmtime(
            _Inout_ struct tm* const _Tm
            )
        {
            return _mkgmtime64(_Tm);
        }

        _Check_return_opt_
        static __inline time_t __CRTDECL mktime(
            _Inout_ struct tm* const _Tm
            )
        {
            return _mktime64(_Tm);
        }

        static __inline time_t __CRTDECL time(
            _Out_opt_ time_t* const _Time
            )
        {
            return _time64(_Time);
        }

        _Check_return_
        static __inline int __CRTDECL timespec_get(
            _Out_ struct timespec* const _Ts,
            _In_  int              const _Base
            )
        {
            return _timespec64_get((struct _timespec64*)_Ts, _Base); 
        }

        #if __STDC_WANT_SECURE_LIB__
            _Check_return_wat_
            static __inline errno_t __CRTDECL ctime_s(
                _Out_writes_(_SizeInBytes) _Post_readable_size_(26) char*         const _Buffer,
                _In_range_(>=,26)                                   size_t        const _SizeInBytes,
                _In_                                                time_t const* const _Time
                )
            {
                return _ctime64_s(_Buffer, _SizeInBytes, _Time);
            }

            _Check_return_wat_
            static __inline errno_t __CRTDECL gmtime_s(
                _Out_ struct tm*    const _Tm,
                _In_  time_t const* const _Time
                )
            {
                return _gmtime64_s(_Tm, _Time);
            }

            _Check_return_wat_
            static __inline errno_t __CRTDECL localtime_s(
                _Out_ struct tm*    const _Tm,
                _In_  time_t const* const _Time
                )
            {
                return _localtime64_s(_Tm, _Time);
            }
        #endif

    #endif // !_USE_32BIT_TIME_T

#endif



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Non-ANSI Names for Compatibility
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#if !__STDC__

    #define CLK_TCK CLOCKS_PER_SEC

    #ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
        _CRT_NONSTDC_DEPRECATE(_tzset) _ACRTIMP void __cdecl tzset(void);
    #endif

#endif // !__STDC__



_CRT_END_C_HEADER