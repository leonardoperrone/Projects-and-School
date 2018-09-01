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
  }

  public countrySelected(country) {
    this.countryClicked.emit(country);
  }

}
