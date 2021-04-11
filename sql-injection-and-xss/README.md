# SQL-Injection
Install the dependencies with
```bash
pip install -r requirements.txt
```
Run `api.py` and open `index.html` in a browser.

There are 5 flags hidden in this database.

# Cross-site-scripting (XSS)

Run `api.py` and open `localhost:5000/xss` and try to find the flag!

The CTF runner must have the xss-bot running with phanthonjs installed:
``` bash
while sleep 10; do phantomjs --ignore-ssl-errors=true --local-to-remote-url-access=true --web-security=false --ssl-protocol=any xss-bot.js; done;
```

### Attribution
modified from: https://github.com/vivek3141/sql-injection-demo

