var events = [
  {'Date': new Date(2022, 1, 12), 'Title': 'Doctor appointment at 3:25pm.', 'Link': 'https://garfield.com'},
  {'Date': new Date(2022, 1, 18), 'Title': 'New Garfield movie comes out!', 'Link': 'https://garfield.com'},
  {'Date': new Date(2022, 1, 27), 'Title': '25 year anniversary', 'Link': 'https://www.google.com.au/#q=anniversary+gifts'},
];
var settings = {
  LinkColor: '#cc0000',
  DisabledDays: [0],
};
var element = document.getElementById('caleandar');
caleandar(element, events, settings);