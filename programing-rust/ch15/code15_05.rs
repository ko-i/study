use std::collections::BTreeSet;

fn main() {
    let mut favorites = BTreeSet::new();

    favorites.insert("Lucy".to_string());
    favorites.insert("Lie".to_string());

    let mut it = favorites.into_iter();

    println!("{:?}", it.next());
    println!("{:?}", it.next());
    println!("{:?}", it.next());
}