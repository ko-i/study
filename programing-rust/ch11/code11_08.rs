pub trait Iterator {
    type Item;   // accociated type

    fn next(*mut self) -> Option<Self::Item>;
}

impl trait for Args {
    type Item = String;

    fn next(&mut self) -> Option<String> {

    }
}

fn collect_to_vector<I: Iterator>(iter: I) -> Vec<I::Item> {
    let mut results = Vec::new();

    for value in iter {
        results.push(value);
    }

    results
}

use std::fmt::Debug;

fn dump<I>(iter: I) where I: Iterator, I::Item: Debug {
    for (index, value) in iter.enumerate() {
        print!("{}: {:?}", index, value);
    }
}