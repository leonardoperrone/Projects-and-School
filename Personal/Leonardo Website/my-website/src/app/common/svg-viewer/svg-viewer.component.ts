import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';

@Component({
  selector: 'app-svg-viewer',
  templateUrl: './svg-viewer.component.html',
  styleUrls: ['./svg-viewer.component.scss']
})
export class SvgViewerComponent implements OnInit, OnChanges {
  @Input() public svgSpecs: any = {};

  constructor() {
  }

  ngOnInit() {
  }

  ngOnChanges(changes: SimpleChanges) {
    if (changes.rotation && this.svgSpecs.dash) {
      this.svgSpecs.dash = ((parseInt(this.svgSpecs.rotation, 10) / 100) * 100 * 3.14).toString();
    }
  }

}
