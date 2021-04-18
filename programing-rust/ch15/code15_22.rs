use std::io::prelude::*;

fn main() {
    let stdin = std::io::stdin();
    println!("{:?}", stdin.lock().lines().count());
}