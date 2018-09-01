import { Component, Input, OnInit } from '@angular/core';

@Component({
  selector: 'app-svg-viewer',
  templateUrl: './svg-viewer.component.html',
  styleUrls: ['./svg-viewer.component.scss']
})
export class SvgViewerComponent implements OnInit {

  @Input() public rotation = '45%';
  @Input() public dash = '141.3000030517578';
  @Input() public gap = '9999';

  constructor() {
  }

  ngOnInit() {
  }

}
