use std::io;
use std::io::prelude::*;
use std::fs::File;
use std::env;
use std::num;
use std::fmt;
use std::error::Error;

use std::process;

#[derive(Debug)]
enum CliError {
    Io(io::Error),
    Parse(num::ParseIntError),
}

impl fmt::Display for CliError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match *self {
            CliError::Io(ref err) => write!(f, "IO error: {}", err),
            CliError::Parse(ref err) => write!(f, "Parse error: {}", err),
        }
    }
}

impl Error for CliError {
    fn description(&self) -> &str {
        match *self {
            CliError::Io(ref err) => err.description(),
            CliError::Parse(ref err) => Error::description(err),
        }
    }

    fn cause(&self) -> Option<&dyn Error> {
        match *self {
            CliError::Io(ref err) => Some(err),
            CliError::Parse(ref err) => Some(err),
        }
    }
}

type ParseResult<i32> = Result<i32, CliError>;

fn run(filename: &str) -> ParseResult<i32> {
    File::open(filename).map_err(CliError::Io).and_then(|mut f| {
        let mut contents = String::new();
        f.read_to_string(&mut contents).map_err(CliError::Io).map(|_| contents)
    }).and_then(|contents| {
        let mut sum = 0;
        for c in contents.lines() {
            match c.parse::<i32>() {
                Ok(n) => sum += n,
                Err(err) => {
                    let err = CliError::Parse(err);
                    println!("Error Info: {} \n Cause by {:?}", err.description(), err.cause());
                },

                // Err(err) => return Err(CliError::Parse(err));,
            }
        }

        Ok(sum)
    })
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let filename = &args[1];
    println!("In file: {:?}", filename);

    match run(filename) {
        Ok(n) => println!("{:?}", n),
        Err(e) => {
            println!("main errir: {}", e);
            process::exit(1);
        },
    }
}