#pragma once

namespace AppInfo {
inline constexpr const char *name() { return APP_NAME; }
inline constexpr const char *version() { return APP_VERSION; }
inline constexpr int major() { return APP_VERSION_MAJOR; }
inline constexpr int minor() { return APP_VERSION_MINOR; }
inline constexpr int patch() { return APP_VERSION_PATCH; }
} // namespace AppInfo
