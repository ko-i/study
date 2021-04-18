use std::cmp::Ordering;
use std::cmp::Ordering::*;

fn compare(m: i32, n: i32) -> Ordering {
    if m < n {
        Less
    } else if m > n {
        Greater
    } else {
        Equal
    }
}