# mysyslog

This project is a system logging library written in C.  It consists of several sub-projects:

*   libmysyslog: The core library providing the basic logging functionality.
*   libmysyslog-text: An extension to libmysyslog that formats log messages as plain text.
*   libmysyslog-json: An extension to libmysyslog that formats log messages as JSON.
*   libmysyslog-client: A client application for sending log messages to a mysyslog-daemon.
*   libmysyslog-daemon: A daemon process that receives and stores log messages.

## Building

Instructions for building the project are provided in each sub-project's README.

## Usage

Examples of how to use the library are provided in the examples/ directory (to be created).

## Dependencies

*   [json-c](https://github.com/json-c/json-c) (for the libmysyslog-json sub-project)

## Contributing

Contributions are welcome!  Please submit a pull request.

## License

[MIT License](LICENSE)
