# Hadolint

Hadolint is Dockerfile linter, validate inline bash, written in Haskell

> It wasn't made recently, it was born in 2016.

## Haskell Dockerfile Linter

A smarter Dockerfile linter that helps you build [best practice](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/) Docker images. The linter parses the Dockerfile into an AST and performs rules on top of the AST. It stands on the shoulders of [ShellCheck](https://github.com/koalaman/shellcheck) to lint the Bash code inside RUN instructions.

## Install

```bash
> brew install hadolint
```

## Run on CLI

```
> hadolint Dockerfile
Dockerfile:1 DL3007 warning: Using latest is prone to errors if the image will ever update. Pin the version explicitly to a release tag

// ignore DL3007.
> hadolint --ignore DL3007 Dockerfile
```

## VSCode extension

There is an official hadolint extension. 
![](./hadolint_extension.png)

## Hadolint in HanaCloud Microservice delivery