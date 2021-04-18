extern crate failure;
#[macro_use] extern crate failure_derive;
use failure::{Context, Fail, Backtrace};
use std::env;
use std::fs::File;
use std::io::prelude::*;

#[derive(Debug)]
pub struct Error {
    inner: Context<ErrorKind>,
}

#[derive(Debug, Fail)]
pub enum ErrorKind {
    #[fail(display = "IoError")]
    Io(#[cause] std::io::Error),

    #[fail(display = "ParseError")]
    Parse(#[cause] std::num::ParseIntError),
}

impl Fail for Error {
    fn cause(&self) -> Option<&Fail> {
        self.inner.cause()
    }

    fn backtrace(&self) -> Option<&Backtrace> {
        self.inner.backtrace()
    } 
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        std::fmt::Display::fmt(&self.inner, f)
    }
}

impl From<std::io::Error> for Error {
    fn from(err: std::io::Error) -> Error {
        Error {
            inner: Context::new(ErrorKind::Io(err, Backtrace::default())),
        }
    }
}

impl From<std::num::ParseIntError> for Error {
    fn from(err: std::num::ParseIntError) -> Error {
        Error {
            inner: Context::new(ErrorKind::Parse(err))
        }
    }
}

type ParseResult<i32> = Result<i32, Error>;

fn main() {
    println!("Hello, world!");
}
