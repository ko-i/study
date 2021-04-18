use std::iter::DoubleEndedIterator;

fn main() {
    let bee_parts = ["head", "thorax", "abdomen"];

    let mut iter = bee_parts.iter();
    println!("{:?}", iter.next());
    println!("{:?}", iter.next_back());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next_back());
    println!("{:?}", iter.next());

    let meals = ["breakfast", "lanch", "dinner"];
    let iter = meals.iter().rev();
    for item in iter {
        println!("{:?}", item);
    }
}