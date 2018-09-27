import { Component, ElementRef, OnInit, ViewChild } from '@angular/core';
import { ToastrService } from 'ngx-toastr';

@Component({
  selector: 'app-about',
  templateUrl: './about.component.html',
  styleUrls: ['./about.component.scss', '../../app.component.scss']
})
export class AboutComponent implements OnInit {
  @ViewChild('email') email: ElementRef;

  public first = '';
  public last = '';
  public isCollapsed = true;
  public showButtonText = 'Show Email';

  constructor(private toastr: ToastrService) {
  }

  ngOnInit() {
  }

  public showEmail() {
    this.isCollapsed = !this.isCollapsed;
    if (!this.isCollapsed) {
      this.first = 'leonardoperrone1994';
      this.last = 'gmail.com';
      this.showButtonText = 'Hide Email';
    } else {
      this.showButtonText = 'Show Email';
    }
  }

  public showSuccess() {
    this.toastr.success('Hello world!');
  }

  public copyEmail() {
    this.email.nativeElement.select();
    try {
      document.execCommand('copy');
      this.showSuccess();
      // this.email.nativeElement.blur();
    } catch (err) {
      alert('Please press Ctrl/Cmd+C to copy');
    }
  }


}
