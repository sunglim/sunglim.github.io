---
layout: post
title:  "Use google sheet API"
categories: jekyll update
---

I'm going to use google sheet like a databas

# How to

Materials:

https://developers.google.com/sheets/api/samples/reading

API를 사용할수있게 설정부터 하여야한다.

https://console.developers.google.com/ 에 들어가면 왼쪽 상단에 프로젝트 이름이 표시가된다.

나의 경우 API Project 라는 이름이고, API 및 서비스 사용설정을 클릭하여 들어간후

Google Sheets API를 추가해준다. 그 다음 왼쪽메뉴에서 사용자 인증정를 클릭한후

사용자 인증정보 만들기를 또 클릭한다.

Client id 를 복사해둔다.  API key를 추가해서 보안을 강화할수있다.

How to enable sheet API: https://www.youtube.com/watch?v=shctaaILCiU&t=1s

Step#1. Create Client ID

Note: If the sheet is public, then we can access the sheet with only API key.
that means we don't need to request authorization.
