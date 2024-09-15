#ifndef LOG_H
#define LOG_H

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>


using namespace std::literals;

#define LOG(...) Logger::GetInstance().Log(__VA_ARGS__)

class Logger {
  auto GetTime() const {
    if (manual_ts_) {
      return *manual_ts_;
    }

    return std::chrono::system_clock::now();
  }

  // auto GetTimeStamp() const {
  //   // const auto now = GetTime();
  //   const time_t t_c = std::chrono::system_clock::to_time_t(GetTime());
  //   return std::put_time(std::localtime(&t_c), "%F %T");
  // }

  // Для имени файла возьмите дату с форматом "%Y_%m_%d"
  std::string GetFileTimeStamp() const {
    std::stringstream ss;
    const auto now = GetTime();
    const auto t_c = std::chrono::system_clock::to_time_t(now);
    ss << std::put_time(std::localtime(&t_c), "%F");
    std::string str = ss.str();
    std::replace(str.begin(), str.end(), '-', '_');
    return str;
  }

  Logger() {
    std::string log_file =
        LOG_DIRECTORY + "sample_log_" + GetFileTimeStamp() + LOG_EXTENSION;
    log_file_.open(log_file, std::ios::app);
  }
  Logger(const Logger &) = delete;

public:
  static Logger &GetInstance() {
    static Logger obj;
    return obj;
  }

  template <class... Ts> void Log(const Ts &...args) {
    std::lock_guard<std::mutex> locker(mutex_);
    log_file_ << /*GetTimeStamp() <<*/ ": "sv;
    ((log_file_ << args), ...);
    log_file_ << std::endl;

    std::cout << /*GetTimeStamp() <<*/ ": "sv;
    ((std::cout << args), ...);
    std::cout << std::endl;
  }

  void SetTimestamp(std::chrono::system_clock::time_point ts) {
    std::lock_guard<std::mutex> locker(mutex_);
    manual_ts_ = ts;
    log_file_.close();
    std::string log_file =
        LOG_DIRECTORY + "sample_log_" + GetFileTimeStamp() + LOG_EXTENSION;
    log_file_.open(log_file, std::ios::app);
  }

  ~Logger() { log_file_.close(); }

private:
  const std::string LOG_DIRECTORY{"/var/log/"};
  std::optional<std::chrono::system_clock::time_point> manual_ts_;
  const std::string LOG_EXTENSION{".log"};
  std::mutex mutex_;
  std::ofstream log_file_;
};

#endif // LOG_H
