import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss', '../../app.component.scss']
})
export class HomeComponent implements OnInit {

  public techMock = {
    technologies: [
      {
        name: 'javascript',
        logos: ['/assets/javascript-logo.png', '/assets/javascript-logo.png'],
        description: 'I had the chance to develop E2E, integration, and unit tests during my first 6 months internship and I enjoyed the scalability that these tests offer in terms of quality assurance. I believe testing is key to proper user experience and to deliver quality products. I think any application should have some automation in place whether or not the application will grow.',
        svgSpecs: {
          rotation: '61',
          dash: '191.5399932861328',
          gap: '9999',
          strokeColor: '#FF7448'
        }
      },
      {
        name: 'angular',
        logos: ['/assets/angular-logo.png'],
        description: ' Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.',
        svgSpecs: {
          rotation: '45',
          dash: '141.3000030517578',
          gap: '9999',
          strokeColor: '#FFC54C'
        }
      },
      {
        name: 'technology',
        logos: ['/assets/javascript-logo.png', '/assets/javascript-logo.png'],
        description: ' Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.',
        svgSpecs: {
          rotation: '61',
          dash: '191.5399932861328',
          gap: '9999',
          strokeColor: '#FF7448'
        }
      },
      {
        name: 'technology',
        logos: ['/assets/javascript-logo.png', '/assets/javascript-logo.png'],
        description: ' Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.',
        svgSpecs: {
          rotation: '61',
          dash: '191.5399932861328',
          gap: '9999',
          strokeColor: '#FF7448'
        }
      },
    ]
  };


  constructor() {
  }

  ngOnInit() {
  }

}
