import {Component, EventEmitter, Input, OnInit, Output} from '@angular/core';

@Component({
  selector: 'app-gallery-viewer',
  templateUrl: './gallery-viewer.component.html',
  styleUrls: ['./gallery-viewer.component.scss']
})
export class GalleryViewerComponent implements OnInit {
  @Output() public countryClicked: EventEmitter<string> = new EventEmitter<string>();
  @Input() public countryName;
  @Input() public countryPics = [];
  @Input() public loaded;

  constructor() {
  }

  ngOnInit() {
    console.log('country name on it in',this.countryPics.map(name=> name));
  }

  public countrySelected(country) {
    this.countryClicked.emit(country);
  }

}
