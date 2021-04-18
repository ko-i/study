pub trait Extend<A> {
    fn entend<T> (&mut self, iter: T) where T: IntoIterator<Item = A>;
}

impl Extend<char> for String {
    fn extend<I: IntoIterator<Item = char>>(&mut self, iter: I) {
        let iterator = iter.into_iter();

        let (lower_bound, _) = iterator.size_hint();
        self.reserve(lower_bound);

        for ch in iterator {
            self.push(ch);
        }
    }
}