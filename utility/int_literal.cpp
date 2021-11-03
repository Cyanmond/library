#pragma once

#include "../utility/int_alias.cpp"
#include <cstddef>
#include <cstdint>

constexpr std::int8_t operator""_i8(unsigned long long n) noexcept { return static_cast<std::int8_t>(n); }
constexpr std::int16_t operator""_i16(unsigned long long n) noexcept { return static_cast<std::int16_t>(n); }
constexpr std::int32_t operator""_i32(unsigned long long n) noexcept { return static_cast<std::int32_t>(n); }
constexpr std::int64_t operator""_i64(unsigned long long n) noexcept { return static_cast<std::int64_t>(n); }

constexpr std::int8_t operator""_u8(unsigned long long n) noexcept { return static_cast<std::uint8_t>(n); }
constexpr std::uint16_t operator""_u16(unsigned long long n) noexcept { return static_cast<std::uint16_t>(n); }
constexpr std::uint32_t operator""_u32(unsigned long long n) noexcept { return static_cast<std::uint32_t>(n); }
constexpr std::uint64_t operator""_u64(unsigned long long n) noexcept { return static_cast<std::uint64_t>(n); }

constexpr isize operator""_iz(unsigned long long n) noexcept { return static_cast<isize>(n); }
constexpr usize operator""_uz(unsigned long long n) noexcept { return static_cast<usize>(n); }