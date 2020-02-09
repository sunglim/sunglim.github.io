---
layout: post
title:  "Project: 환율 알람"
categories: jekyll update
---

Recently I decided to create a website to help my stock trading.

The website would have

- Currency
- Bitcoin price
- KOSPI, S&P 500 index, Dow, and Nasdaq index

Above values are that I keep watching every day.


1. Batch script running daily.
  - Use Google Clound Function(https://cloud.google.com/functions/)
  - Google clound Trial project is free.

2. Database
 - Instead of using realtime database like MS SQL. I decided to use google sheet
   as a database. Google sheeet provide a bunch of API that I can easily use.

# Study Plan
  Google Clound Function(https://cloud.google.com/functions/)

  1. HTTP Tutorial

  https://cloud.google.com/functions/docs/tutorials/http

  To use the google cloud, Google Cloud SDK Installer should be installed first.

  project: blog-test-project-262907 is selected

  In this tutorial, we deploy node project to gcloud

  https://REGION-PROJECT_ID.cloudfunctions.net/helloGET

  invoked by HTTP request.

  2. Serverless web performance monitoring using cloud functions

  https://cloud.google.com/solutions/serverless-web-performance-monitoring-using-cloud-functions

# TODO
  Write a script to get data from google sheet. and use it on my blog.

  Write up-to-date currency to spread sheet using google cloud function

  Write node project that writes currency to google sheet

  study cloud scheduler https://cloud.google.com/scheduler/docs/quickstart/

# Info
  [Cloud Scheduler]<https://cloud.google.com/scheduler/> manages cron job service.

  Google Cloud Scheduler를 이용하여 cronjob을 만들수가 있음. 이때 트리거 당하는쪽은
  pub/sub방식 http방식 혹은 app engine 이 될수가 있음. 
  cloud scheduler 자체는 상당히 간단한 그냥 트리거만 시켜줌. 구현은 각각에서 해야함.

  이 펑션은  google clound function으로 구현가능, 혹은 firebase도 pubsub지원

  pub/sub 이해 https://cloud.google.com/pubsub/docs/quickstart-py-mac
