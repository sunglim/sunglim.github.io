const search = instantsearch({
  indexName: 'jekyll_blog',
  searchClient: algoliasearch(
    'I2X1XFAM0D',
    '9db8946e9f3cae61db59553cf54dee6b'
  ),
	searchFunction: function(helper) {
    const container = document.querySelector('#hits');

		if (helper.state.query === '') {
			container.style.display = 'none';
		} else {
			container.style.display = '';
			helper.search();
		}
	}
});

search.addWidgets([
  instantsearch.widgets.searchBox({
    container: '#search-box',
  }),
  instantsearch.widgets.hits({
    container: '#hits',
    templates: {
      empty: 'No results for <q>{{ query }}</q>',
    },
  })
]);

search.start();
