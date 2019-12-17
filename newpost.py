#!/usr/bin/env python

assert __name__ == '__main__'

import imp
import os
import pipes
import subprocess
import sys
from datetime import date
import datetime
from datetime import datetime
from datetime import time, tzinfo, timedelta
import time

#date:   2019-12-17 20:00:35 +0900

def main():
    today = date.today()

    # e.g. 2019-12-17
    formated_today = today.strftime("%Y-%m-%d")

    file_name = formated_today + '-english.markdown'
    
    template = '''
---
layout: post
title:  "{title}"
date:  {date} 
categories: jekyll update
---

{content}
'''
    date_in_post = time.strftime('%Y-%m-%d %H:%M:%S %z')
    template = template.replace('{date}', date_in_post)

    f = open("./_posts/" + file_name, "a")
    f.write(template)
    f.close()

assert __name__ == '__main__'
main()
