# CTF-challenges

See [my blog](https://www.openlearning.com/u/lukeos/blog/SomethingAwesomeProposal/) for context behind this project. Each challenge contains one or more flags which must be found by analysing the files given, or breaching the website/database.

### Flag count
* Steganography: 7 flags
* SQL Injection: 7 flags
* Reflected XSS: 1 flag
* Networking: 4 flags
* Reverse Engineering: 4 flags


### Running

I have integrated the challenges together into the website for ease of use.

You will need to run:
* `cd CTF-challenges/sql-injection-and-xss`
* `python3 api.py`
* `while sleep 10; do phantomjs --ignore-ssl-errors=true --local-to-remote-url-access=true --web-security=false --ssl-protocol=any xss-bot.js; done;`
* Then just open `localhost:5000` in your browser!

note: I need to do `export OPENSSL_CONF="/tmp/openssl.cnf"` to fix a bug in phantomjs