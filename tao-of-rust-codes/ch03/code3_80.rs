trait StreamingIterator {
    type Item<'a>;

    fn next<'a>(&'a mut self) -> Option<Self::Item<'a>>;
}