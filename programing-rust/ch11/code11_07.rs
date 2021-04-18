trait StringSet {
    fn new() -> Self;

    fn from_slice(strings: &[&str]) -> Self;

    fn contains(&self, string: &str) -> bool;

    fn add(&mut self, string: &str);
}

fn unknown_words<S: StringSet>(document: &Vec<String>, wordlist: &S) -> S {
    let mut unknowns = S::new();

    for word in document {
        if !wordlist.contains(word) {
            unknowns.add(word);
        }
    }

    unknowns
}

fn main() {
    let set1 = SortedStringSet::new();
    let set2 = HashedStringSet::new();
}